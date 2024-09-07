#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include "event.h"
#include <iostream>
#include <map>
#include <utility>

class EventQueue {
public:
  EventQueue() = default;

  // Rule of five - no copy or move.
  EventQueue(const EventQueue &) = delete;
  EventQueue(EventQueue &&) = delete;
  EventQueue &operator=(const EventQueue &other) = delete;
  EventQueue &operator=(EventQueue &&other) = delete;
  ~EventQueue() = default;

  void insert(Event event, Instant time) { _queue.emplace(time, event); }

  std::pair<Instant, Event> take_next_event() {
    const auto &queue_start = _queue.begin();
    if (queue_start == _queue.end()) {
      throw std::runtime_error("No more events, stopping simulation");
    }
    std::pair<Instant, Event> first_event = *queue_start;
    _queue.erase(queue_start);
    return first_event;
  }

private:
  std::multimap<Instant, Event> _queue;
};

#endif // EVENT_QUEUE_H
