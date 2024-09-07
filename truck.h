#ifndef TRUCK_H
#define TRUCK_H

#include "clock.h"
#include <iostream>

// Indicate that the truck is not at an unload station.
constexpr int NO_STATION = -1;

class Truck {
public:
  Truck() {}

  // Rule of five - no copy or move.
  Truck(const Truck &) = delete;
  Truck(Truck &&) = delete;
  Truck &operator=(const Truck &other) = delete;
  Truck &operator=(Truck &&other) = delete;
  ~Truck() = default;

  int id() const { return _id; }
  int station() const { return _station_id; }
  void set_station(int station_id) { _station_id = station_id; }

  void release_from_station() {
    _station_id = NO_STATION;
    ++_unload_count;
  }

  void add_travel_time() {
    _travel_time += (Clock::now() - _last_event);
    _last_event = Clock::now();
  }

  void add_queued_time() {
    _queued_time += (Clock::now() - _last_event);
    _last_event = Clock::now();
  }

  void add_load_time() {
    _load_time += (Clock::now() - _last_event);
    _last_event = Clock::now();
  }

  void add_unload_time() {
    _unload_time += (Clock::now() - _last_event);
    _last_event = Clock::now();
  }

  void print_stats() {
    std::cout << "Truck " << _id << ": unloaded " << _unload_count
              << " time(s), travel time " << _travel_time << ", queued time "
              << _queued_time << ", load time " << _load_time
              << ", unload time " << _unload_time << std::endl;
  }

private:
  inline static int _next_id{0};
  const int _id{_next_id++};
  int _station_id{NO_STATION};
  int _unload_count{};
  Instant _last_event{Clock::now()};
  Duration _travel_time{};
  Duration _queued_time{};
  Duration _load_time{};
  Duration _unload_time{};
};

#endif // TRUCK_H
