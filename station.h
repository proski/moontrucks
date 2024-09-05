#include <iostream>

class Station {
public:
  Station() { std::cout << "Creating station " << _id << std::endl; }

  ~Station() { std::cout << "Destroying station " << _id << std::endl; }

  int get_id() { return _id; };

private:
  inline static int _next_id = 0;
  const int _id{_next_id++};
};
