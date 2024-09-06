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
    for (auto truck = _trucks.begin(); truck != _trucks.end(); ++truck) {
      Event event = Event{EventType::MiningComplete, truck->id()};
      // The duration is random between 1 hour and 5 hours
      Duration duration =
          Clock::hours(1) + (Clock::hours(4) * rand() / RAND_MAX);
      std::cout << "Event for truck " << truck->id() << " duration " << duration
                << std::endl;
      event_queue.insert(event, Clock::now() + duration);
    }
  }

  // Rule of five - no copy
  Fleet(const Fleet &) = delete;
  Fleet(Fleet &&) = default;
  Fleet &operator=(const Fleet &other) = delete;
  Fleet &operator=(Fleet &&other) = default;
  ~Fleet() { std::cout << "Destroying truck fleet" << std::endl; }

  int get_truck_count() { return _truck_count; };

private:
  const int _truck_count;
  std::vector<Truck> _trucks;
};

#endif // FLEET_H
