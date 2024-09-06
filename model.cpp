#include "model.h"
#include "clock.h"

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
    Instant next_event_time = Clock::now() + Clock::minutes(30);
    _event_queue.insert(next_event, next_event_time);
    break;
  }
  case EventType::ArrivedToStations: {
    std::cout << time << ": ArrivedToStations " << truck_id << std::endl;
    // queue_truck();
    break;
  }
  case EventType::UnloadComplete: {
    std::cout << time << ": UnloadComplete " << truck_id << std::endl;
    break;
  }
  case EventType::ArrivedToMine: {
    std::cout << time << ": ArrivedToMine " << truck_id << std::endl;
    break;
  }
  }
}
