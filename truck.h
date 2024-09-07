#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>

// Indicate that the truck is not at an unload station.
constexpr int NO_STATION = -1;

class Truck {
public:
  Truck() { std::cout << "Creating truck " << _id << std::endl; }

  // Rule of five - no copy or move.
  Truck(const Truck &) = delete;
  Truck(Truck &&) = delete;
  Truck &operator=(const Truck &other) = delete;
  Truck &operator=(Truck &&other) = delete;
  ~Truck() { std::cout << "Destroying truck " << _id << std::endl; }

  int id() const { return _id; }
  int station() const { return _station_id; }
  void set_station(int station_id) { _station_id = station_id; }
  int unload_count() const { return _unload_count; }
  void release_from_station() {
    _station_id = NO_STATION;
    ++_unload_count;
  }

private:
  inline static int _next_id{0};
  const int _id{_next_id++};
  int _station_id{NO_STATION};
  int _unload_count{0};
};

#endif // TRUCK_H
