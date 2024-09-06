#ifndef UNLOAD_SITE_H
#define UNLOAD_SITE_H

#include "station.h"
#include <iostream>
#include <vector>

class UnloadSite {
public:
  UnloadSite(int station_count)
      : _station_count(station_count), _stations(station_count) {
    std::cout << "Creating unload site of " << station_count << " stations"
              << std::endl;
  }

  // Rule of five - no copy
  UnloadSite(const UnloadSite &) = delete;
  UnloadSite(UnloadSite &&) = default;
  UnloadSite &operator=(const UnloadSite &other) = delete;
  UnloadSite &operator=(UnloadSite &&other) = default;
  ~UnloadSite() { std::cout << "Destroying unload site" << std::endl; }

  int get_station_count() { return _station_count; };

private:
  const int _station_count;
  std::vector<Station> _stations;
};

#endif // UNLOAD_SITE_H
