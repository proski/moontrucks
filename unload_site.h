#ifndef UNLOAD_SITE_H
#define UNLOAD_SITE_H

#include "event_queue.h"
#include "station.h"
#include <iostream>
#include <vector>

class UnloadSite {
public:
  UnloadSite(int station_count)
      : _station_count(station_count), _stations(station_count) {
    std::cout << "Creating unload site of " << station_count << " stations"
              << std::endl;
  }

  // Rule of five - no copy
  UnloadSite(const UnloadSite &) = delete;
  UnloadSite(UnloadSite &&) = default;
  UnloadSite &operator=(const UnloadSite &other) = delete;
  UnloadSite &operator=(UnloadSite &&other) = default;
  ~UnloadSite() { std::cout << "Destroying unload site" << std::endl; }

  void queue_truck(Truck &truck, EventQueue &event_queue) {
    bool initial = true;
    int shortest_queue = 0;
    int best_station = 0;

    for (const auto &station : _stations) {
      const int queue_length = station.queue_length();
      if (initial || queue_length < shortest_queue) {
        shortest_queue = queue_length;
        best_station = station.id();
        initial = false;
      }
    }
    _stations[best_station].enqueue_truck(truck, event_queue);
  };

  void release_truck(Truck &truck, EventQueue &event_queue) {
    Station &station = _stations[truck.station()];
    station.release_truck(truck, event_queue);
  }

private:
  const int _station_count;
  std::vector<Station> _stations;
};

#endif // UNLOAD_SITE_H
