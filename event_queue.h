#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include "clock.h"
#include "event.h"
#include <iostream>
#include <map>

class EventQueue {
public:
  EventQueue() : _queue{} { std::cout << "Creating event queue" << std::endl; };

  // Rule of five - no copy
  EventQueue(const EventQueue &) = delete;
  EventQueue(EventQueue &&) = default;
  EventQueue &operator=(const EventQueue &other) = delete;
  EventQueue &operator=(EventQueue &&other) = default;
  ~EventQueue() { std::cout << "Destroying event queue" << std::endl; };

  void insert(Event event, Instant time) { _queue.insert({time, event}); }

  void process_next_event() {
    const auto &first_element = _queue.begin();
    if (first_element == _queue.end()) {
      throw std::runtime_error("No more events, stopping simulation");
    }
    auto [time, event] = *first_element;
    _queue.erase(first_element);
    std::cout << "Event time " << time << " type "
              << static_cast<int>(event.event_type()) << " truck "
              << event.truck_id() << std::endl;
  }

private:
  std::multimap<Instant, Event> _queue;
  int elapsed_time{0};
  Event get_next_event();
};

#endif // EVENT_QUEUE_H
