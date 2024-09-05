#include "event.h"
#include <queue>

class EventQueue {
public:
  EventQueue() : _queue{} {};
  ~EventQueue() {};
  void add_event(Event event);
  Event get_next_event();

private:
  std::queue<Event> _queue;
};
