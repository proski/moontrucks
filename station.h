#ifndef STATION_H
#define STATION_H

#include "clock.h"
#include "event.h"
#include "event_queue.h"
#include "parameters.h"
#include <iostream>
#include <queue>

class Station {
public:
  Station() {}

  // Rule of five - no copy or move.
  Station(const Station &) = delete;
  Station(Station &&) = delete;
  Station &operator=(const Station &other) = delete;
  Station &operator=(Station &&other) = delete;
  ~Station() = default;

  int id() const { return _id; }
  int queue_length() const { return _truck_queue.size(); }

  void enqueue_truck(Truck &truck, EventQueue &event_queue) {
    bool queue_empty = queue_length() == 0;
    _truck_queue.push(truck.id());
    truck.set_station(_id);
    if (queue_empty) {
      event_queue.insert({EventType::UnloadComplete, truck.id()},
                         Clock::from_now(UNLOAD_TIME));
      add_idle_time();
    }
  }

  void release_truck(const Truck &truck, Fleet &fleet,
                     EventQueue &event_queue) {
    int truck_id = _truck_queue.front();
    if (truck_id != truck.id()) {
      std::cerr << "First truck is line is " << truck_id << " but truck "
                << truck.id() << " has been unloaded" << std::endl;
    }
    _truck_queue.pop();
    if (queue_length() > 0) {
      int next_truck_id = _truck_queue.front();
      event_queue.insert({EventType::UnloadComplete, next_truck_id},
                         Clock::from_now(UNLOAD_TIME));
      Truck &truck = fleet.truck(next_truck_id);
      truck.add_queued_time();
    }
    ++_unload_count;
    add_unload_time();
  }

  void add_idle_time() {
    _idle_time += (Clock::now() - _last_event);
    _last_event = Clock::now();
  }

  void add_unload_time() {
    _unload_time += (Clock::now() - _last_event);
    _last_event = Clock::now();
  }

  void print_stats() const {
    std::cout << "Station " << _id << ": unloaded " << _unload_count
              << " time(s), idle time " << _idle_time << ", unload time "
              << _unload_time << std::endl;
  }

private:
  inline static int _next_id{0};
  const int _id{_next_id++};
  std::queue<int> _truck_queue{};

  // Stats
  int _unload_count{};
  Instant _last_event{Clock::now()};
  Duration _idle_time{};
  Duration _unload_time{};
};

#endif // STATION_H
