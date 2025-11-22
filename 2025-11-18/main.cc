// Аверкина В.О. ТИДИ25
// ДЗ до 24.11 23:59

#include "dyn_arr.h"
#include <iostream>

int main() {
  DynamicArray arr;
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(5);
  arr.printData();
  arr.push_front(24);
  arr.printData();
  arr.insert(2, 99);
  arr.printData();
  arr.erase(2); 
  arr.printData();  
  arr.erase_after(2);
  arr.printData();
  arr.increase_capacity(10);
  arr.push_back(11);
  arr.push_back(12);
  arr.push_front(13);
  arr.push_front(14);
  arr.printData();
  arr.decrease_capacity(5);
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
