#include "model.h"
#include "clock.h"
#include "parameters.h"
#include <iostream>

void Model::process_next_event() {
  auto [time, event] = _event_queue.take_next_event();
  Clock::set_time(time);
  EventType event_type = event.event_type();
  int truck_id = event.truck_id();
  Truck &truck = _fleet.truck(truck_id);

  switch (event_type) {
  case EventType::MiningComplete: {
    std::cout << time << ": MiningComplete " << truck_id << std::endl;
    _event_queue.insert({EventType::ArrivedToStations, truck_id},
                        Clock::from_now(TRAVEL_TO_STATION));
    break;
  }
  case EventType::ArrivedToStations: {
    std::cout << time << ": ArrivedToStations " << truck_id << std::endl;
    _unload_site.queue_truck(truck, _event_queue);
    break;
  }
  case EventType::UnloadComplete: {
    std::cout << time << ": UnloadComplete " << truck_id << std::endl;
    _unload_site.release_truck(truck, _event_queue);
    _event_queue.insert({EventType::ArrivedToMine, truck_id},
                        Clock::from_now(TRAVEL_TO_MINE));
    break;
  }
  case EventType::ArrivedToMine: {
    std::cout << time << ": ArrivedToMine " << truck_id << std::endl;
    //  The duration is random between 1 hour and 5 hours
    Duration duration = MINING_TIME_MIN + ((MINING_TIME_MAX - MINING_TIME_MIN) *
                                           rand() / RAND_MAX);
    _event_queue.insert({EventType::MiningComplete, truck_id},
                        Clock::from_now(duration));
    break;
  }
  }
}

void Model::run_simulation() {
  while (Clock::now() < SIMULATION_TIME) {
    process_next_event();
  }
  for (int truck_id = 0; truck_id < _truck_count; ++truck_id) {
    Truck &truck = _fleet.truck(truck_id);
    std::cout << "Truck " << truck_id << " unloaded " << truck.unload_count()
              << " time(s)" << std::endl;
  }
}
