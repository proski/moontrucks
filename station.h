#ifndef STATION_H
#define STATION_H

#include "clock.h"
#include "event.h"
#include "event_queue.h"
#include <iostream>
#include <queue>

const Duration UNLOAD_TIME = Clock::minutes(5);

class Station {
public:
  Station() { std::cout << "Creating station " << _id << std::endl; }

  // Rule of five - copy and move allowed
  Station(const Station &) = default;
  Station(Station &&) = default;
  Station &operator=(const Station &other) = default;
  Station &operator=(Station &&other) = default;
  ~Station() { std::cout << "Destroying station " << _id << std::endl; }

  int id() const { return _id; }
  int queue_length() const { return _truck_queue.size(); }

  void enqueue_truck(Truck &truck, EventQueue &event_queue) {
    _truck_queue.push(truck.id());
    truck.set_station(_id);
    if (queue_length() == 0) {
      event_queue.insert({EventType::UnloadComplete, truck.id()},
                         Clock::now() + UNLOAD_TIME);
    }
  }

  void release_truck(Truck &truck, EventQueue &event_queue) {
    int truck_id = _truck_queue.front();
    if (truck_id != truck.id()) {
      std::cerr << "First truck is line is " << truck_id << " but truck "
                << truck.id() << " has been unloaded" << std::endl;
    }
    _truck_queue.pop();
    if (queue_length() > 0) {
      truck_id = _truck_queue.front();
      event_queue.insert({EventType::UnloadComplete, truck_id},
                         Clock::now() + UNLOAD_TIME);
    }
  }

private:
  inline static int _next_id{0};
  const int _id{_next_id++};
  std::queue<int> _truck_queue{};
};

#endif // STATION_H
