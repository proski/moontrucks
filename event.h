#ifndef EVENT_H
#define EVENT_H

#include "clock.h"
#include <cstdlib>

enum class EventType {
  Mining,
  TravelToMine,
  TravelFromMine,
  Unloading,
  UnloadWait,
};

class Event {
public:
  static Event mining() {
    // The duration is random between 1 hour and 5 hours
    Duration duration = 60.0 + (4 * 60.0 * rand() / RAND_MAX);
    Instant instant = Clock::now() + duration;
    return Event(EventType::Mining, instant);
  }

  Event(const Event &) = default;
  Event(Event &&) = default;
  Event &operator=(const Event &other) = default;
  Event &operator=(Event &&other) = default;
  ~Event() = default;

  Instant time() { return this->_time; }

private:
  EventType _event_type;
  Instant _time;

  Event(EventType event_type, Instant time)
      : _event_type(event_type), _time(time) {}
};

#endif // EVENT_H
