#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>

class Truck {
public:
  Truck() { std::cout << "Creating truck " << _id << std::endl; }

  // Rule of five - copy and move allowed
  Truck(const Truck &) = delete;
  Truck(Truck &&) = default;
  Truck &operator=(const Truck &other) = delete;
  Truck &operator=(Truck &&other) = default;
  ~Truck() { std::cout << "Destroying truck " << _id << std::endl; }

  int id() const { return _id; }
  int station() const { return _station_id; }
  void set_station(int station_id) { _station_id = station_id; }

private:
  inline static int _next_id{0};
  const int _id{_next_id++};
  int _station_id{0};
};

#endif // TRUCK_H
