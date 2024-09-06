#ifndef EVENT_H
#define EVENT_H

enum class EventType {
  MiningComplete,
  ArrivedToStations,
  UnloadComplete,
  ArrivedToMine,
};

class Event {
public:
  Event(EventType event_type, int truck_id)
      : _event_type(event_type), _truck_id(truck_id) {}

  // Rule of five - copy and move allowed
  Event(const Event &) = default;
  Event(Event &&) = default;
  Event &operator=(const Event &other) = default;
  Event &operator=(Event &&other) = default;
  ~Event() = default;

  EventType event_type() { return _event_type; }
  int truck_id() { return _truck_id; }

private:
  const EventType _event_type;
  const int _truck_id;
};

#endif // EVENT_H
