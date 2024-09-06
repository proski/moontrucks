#include "fleet.h"
#include "unload_site.h"
#include <iostream>

void usage() {
  std::cout << "Usage:" << std::endl
            << "moontrucks N M" << std::endl
            << "N: number of trucks" << std::endl
            << "M: number of unload stations" << std::endl;
}

void run_model(const int truck_count, const int station_count) {
  EventQueue event_queue;
  Fleet fleet{truck_count, event_queue};
  UnloadSite unload_site{station_count};
}

int main(int argc, char *argv[]) {
  int truck_count = -1;
  int station_count = -1;

  std::cout << "Moon mining trucks simulator" << std::endl;

  if (argc != 3) {
    usage();
    return 1;
  }

  try {
    truck_count = std::stoi(argv[1]);
    station_count = std::stoi(argv[2]);
  } catch (std::invalid_argument &e) {
    std::cerr << "Exception caught : " << e.what() << std::endl;
    return 2;
  }

  if (truck_count < 0 || station_count < 0) {
    std::cerr << "Unsupported arguments" << std::endl;
    return 3;
  }

  run_model(truck_count, station_count);
  return 0;
}
