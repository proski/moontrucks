#ifndef FLEET_H
#define FLEET_H

#include "clock.h"
#include "event.h"
#include "event_queue.h"
#include "truck.h"
#include <cstdlib>
#include <iostream>
#include <vector>

class Fleet {
public:
  Fleet(int truck_count, EventQueue &event_queue)
      : _truck_count(truck_count), _trucks(truck_count) {
    std::cout << "Creating fleet of " << truck_count << " trucks" << std::endl;
    for (const auto &truck : _trucks) {
      event_queue.insert({EventType::ArrivedToMine, truck.id()}, Clock::now());
    }
  }

  // Rule of five - no copy or move.
  Fleet(const Fleet &) = delete;
  Fleet(Fleet &&) = delete;
  Fleet &operator=(const Fleet &other) = delete;
  Fleet &operator=(Fleet &&other) = delete;
  ~Fleet() { std::cout << "Destroying truck fleet" << std::endl; }

  Truck &truck(int truck_id) { return _trucks[truck_id]; }

private:
  const int _truck_count;
  std::vector<Truck> _trucks;
};

#endif // FLEET_H
