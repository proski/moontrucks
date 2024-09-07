#ifndef FLEET_H
#define FLEET_H

#include "clock.h"
#include "event.h"
#include "event_queue.h"
#include "truck.h"
#include <vector>

class Fleet {
public:
  Fleet(int truck_count, EventQueue &event_queue)
      : _truck_count(truck_count), _trucks(truck_count) {
    for (const auto &truck : _trucks) {
      event_queue.insert({EventType::ArrivedToMine, truck.id()}, Clock::now());
    }
  }

  // Rule of five - no copy or move.
  Fleet(const Fleet &) = delete;
  Fleet(Fleet &&) = delete;
  Fleet &operator=(const Fleet &other) = delete;
  Fleet &operator=(Fleet &&other) = delete;
  ~Fleet() = default;

  Truck &truck(int truck_id) { return _trucks[truck_id]; }

  void print_stats() const {
    for (const auto &truck : _trucks) {
      truck.print_stats();
    }
  }

private:
  const int _truck_count;
  std::vector<Truck> _trucks;
};

#endif // FLEET_H
