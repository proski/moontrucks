#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include "clock.h"
#include "event.h"
#include <iostream>
#include <map>

class EventQueue {
public:
  EventQueue() : _queue{} { std::cout << "Creating event queue" << std::endl; };

  ~EventQueue() { std::cout << "Destroying event queue" << std::endl; };

  void insert(Event event, Instant time) { _queue.insert({time, event}); }

  void process_next_event();

private:
  std::multimap<Instant, Event> _queue;
  int elapsed_time{0};
  Event get_next_event();
};

#endif // EVENT_QUEUE_H
