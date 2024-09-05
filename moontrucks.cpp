#include <iostream>

void usage() {
  std::cout << "Usage:" << std::endl
            << "moontrucks N M" << std::endl
            << "N: number of trucks" << std::endl
            << "M: number of unload stations" << std::endl;
}

void run_model(const int truck_count, const int unloader_count) {
  std::cout << "Number of trucks: " << truck_count << std::endl;
  std::cout << "Number of unload stations: " << unloader_count << std::endl;
  for (int i = 0; i < truck_count; ++i) {
    std::cout << "Creating truck " << i << std::endl;
  }
  for (int i = 0; i < unloader_count; ++i) {
    std::cout << "Creating unload station " << i << std::endl;
  }
}

int main(int argc, char *argv[]) {
  int truck_count = -1;
  int unloader_count = -1;

  std::cout << "Moon mining trucks simulator" << std::endl;

  if (argc != 3) {
    usage();
    return 1;
  }

  try {
    truck_count = std::stoi(argv[1]);
    unloader_count = std::stoi(argv[2]);
  } catch (std::invalid_argument &e) {
    std::cerr << "Exception caught : " << e.what() << std::endl;
    return 2;
  }

  if (truck_count < 0 || unloader_count < 0) {
    std::cerr << "Unsupported arguments" << std::endl;
    return 3;
  }

  run_model(truck_count, unloader_count);
  return 0;
}
