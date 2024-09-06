#ifndef STATION_H
#define STATION_H

#include <iostream>

class Station {
public:
  Station() { std::cout << "Creating station " << _id << std::endl; }

  // Rule of five - copy and move allowed
  Station(const Station &) = default;
  Station(Station &&) = default;
  Station &operator=(const Station &other) = default;
  Station &operator=(Station &&other) = default;
  ~Station() { std::cout << "Destroying station " << _id << std::endl; }

  int get_id() { return _id; };

private:
  inline static int _next_id = 0;
  const int _id{_next_id++};
};

#endif // STATION_H
