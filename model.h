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
        _event_queue(), _fleet(truck_count, _event_queue),
        _unload_site(station_count) {
    std::cout << "Initializing model" << std::endl;

    // Seed random number generator with the current time to have different
    // results for every run.
    srand(std::time(NULL));
  }

  // Rule of five - no copy
  Model(const Model &) = delete;
  Model(Model &&) = default;
  Model &operator=(const Model &other) = delete;
  Model &operator=(Model &&other) = default;
  ~Model() = default;

  void run_simulation() {
    while (Clock::now() < Clock::hours(72)) {
      process_next_event();
    }
  }

  void process_next_event();

private:
  EventQueue _event_queue;
  Fleet _fleet;
  UnloadSite _unload_site;
  const int _truck_count;
  const int _station_count;
  int elapsed_time{0};
};

#endif // MODEL_H
