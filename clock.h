#ifndef CLOCK_H
#define CLOCK_H

typedef double Duration;
typedef double Instant;

class Clock {
public:
  static Instant now() { return _now; };

  static void advance(Duration duration) { _now += duration; }

private:
  Clock() {}
  ~Clock() {}
  inline static Instant _now{0.0};
};

#endif // CLOCK_H
