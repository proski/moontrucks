enum class EventType {
  Mining,
  TravelToMine,
  TravelFromMine,
  Unloading,
  UnloadWait,
};

typedef double EventDuration;

class Event {
public:
  EventType event_type;
  EventDuration duration;
};
