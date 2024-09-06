#include "model.h"
#include "clock.h"

const Duration MINING_TIME_MIN = Clock::hours(1);
const Duration MINING_TIME_MAX = Clock::hours(5);
const Duration TRAVEL_TO_MINE = Clock::minutes(30);
const Duration TRAVEL_TO_STATION = Clock::minutes(30);

void Model::process_next_event() {
  auto [time, event] = _event_queue.take_next_event();
  EventType event_type = event.event_type();
  int truck_id = event.truck_id();
  Clock::set_time(time);

  switch (event_type) {
  case EventType::MiningComplete: {
    std::cout << time << ": MiningComplete " << truck_id << std::endl;
    EventType next_event_type = EventType::ArrivedToStations;
    Event next_event{next_event_type, truck_id};
    Instant next_event_time = Clock::now() + TRAVEL_TO_STATION;
    _event_queue.insert(next_event, next_event_time);
    break;
  }
  case EventType::ArrivedToStations: {
    std::cout << time << ": ArrivedToStations " << truck_id << std::endl;
    //_unload_site.queue_truck(truck_id);
    break;
  }
  case EventType::UnloadComplete: {
    std::cout << time << ": UnloadComplete " << truck_id << std::endl;
    //_unload_site.release_truck(truck_id);
    _event_queue.insert({EventType::ArrivedToMine, truck_id},
                        Clock::now() + TRAVEL_TO_MINE);
    break;
  }
  case EventType::ArrivedToMine: {
    std::cout << time << ": ArrivedToMine " << truck_id << std::endl;
    //  The duration is random between 1 hour and 5 hours
    Duration duration = MINING_TIME_MIN + ((MINING_TIME_MAX - MINING_TIME_MIN) *
                                           rand() / RAND_MAX);
    _event_queue.insert({EventType::MiningComplete, truck_id},
                        Clock::now() + duration);
    break;
  }
  }
}
