#include "dyn_arr.h"
#include <iostream>

int main() {
  DynamicArray arr;
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(5);
  arr.printData();
  std::cout << arr.min() << std::endl;
  std::cout << arr.max() << std::endl;
  std::cout << arr.add(0, 2) << std::endl;
  // arr.clear();
  arr.printData();
  std::cout << arr[2] << std::endl;
  // std::cout << arr.operator[](2) << std::endl;
  // std::cout << arr() << std::endl;
  std::cout << arr.operator()() << std::endl;
  return 0;
}
