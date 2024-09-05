#include "truck.h"
#include <iostream>
#include <vector>

class Fleet {
public:
  Fleet(int truck_count) : _truck_count(truck_count), _trucks(truck_count) {
    std::cout << "Creating fleet of " << truck_count << " trucks" << std::endl;
  }

  ~Fleet() { std::cout << "Destroying truck fleet" << std::endl; }

  int get_truck_count() { return _truck_count; };

private:
  const int _truck_count;
  std::vector<Truck> _trucks;
};
