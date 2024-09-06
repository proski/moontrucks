#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include "event.h"
#include <iostream>
#include <map>

class EventQueue {
public:
  EventQueue() : _queue{} { std::cout << "Creating event queue" << std::endl; };

  ~EventQueue() { std::cout << "Destroying event queue" << std::endl; };

  void insert(Event event) { _queue.insert({event.time(), event}); }

  void process_next_event();

private:
  std::map<Instant, Event> _queue;
  int elapsed_time{0};
  Event get_next_event();
};

#endif // EVENT_QUEUE_H
