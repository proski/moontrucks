#ifndef CLOCK_H
#define CLOCK_H

#include <stdexcept>

// Represented in minutes internally
typedef double Duration;
typedef double Instant;

class Clock {
public:
  static Instant now() { return _now; };

  static void set_time(Instant instant) {
    if (instant < _now) {
      throw std::runtime_error("Time goes backwards");
    }
    _now = instant;
  }

  static constexpr Duration hours(int hours) { return 60.0 * hours; }
  static constexpr Duration minutes(int minutes) { return 1.0 * minutes; }

private:
  Clock() {}
  ~Clock() {}
  inline static Instant _now{0.0};
};

#endif // CLOCK_H
