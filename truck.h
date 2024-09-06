#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>

class Truck {
public:
  Truck() { std::cout << "Creating truck " << _id << std::endl; }

  ~Truck() { std::cout << "Destroying truck " << _id << std::endl; }

  int get_id() { return _id; };

private:
  inline static int _next_id = 0;
  const int _id{_next_id++};
};

#endif // TRUCK_H
