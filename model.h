#ifndef MODEL_H
#define MODEL_H

#include "clock.h"
#include "event_queue.h"
#include "fleet.h"
#include "unload_site.h"
#include <ctime>
#include <iostream>

class Model {
public:
  Model(int truck_count, int station_count)
      : _truck_count(truck_count), _station_count(station_count),
        _fleet(truck_count, _event_queue), _unload_site(station_count) {
    // Seed random number generator with the current time to have different
    // results for every run.
    srand(std::time(NULL));
  }

  // Rule of five - no copy or move.
  Model(const Model &) = delete;
  Model(Model &&) = delete;
  Model &operator=(const Model &other) = delete;
  Model &operator=(Model &&other) = delete;
  ~Model() = default;

  void run_simulation();

  void process_next_event();

private:
  EventQueue _event_queue{};
  Fleet _fleet;
  UnloadSite _unload_site;
  const int _truck_count;
  const int _station_count;
};

#endif // MODEL_H
