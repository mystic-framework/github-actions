// Main Entry

#include <iostream>

#include "dummy.hpp"

int main() {
  std::cout << "Hello, World!" << std::endl;
  std::cout << "add(2, 3) = " << add(2, 3) << std::endl;
  std::cout << "returnFourtyTwo() = " << returnFourtyTwo() << std::endl;
  std::cout << "returnTrue() = " << std::boolalpha << returnTrue() << std::endl;
  return 0;
}
