#ifndef DYN_ARR_H
#define DYN_ARR_H

#include <cstdint>
// size_t == unsigned long long

class DynamicArray {
private:
  float* data;
  std::int64_t size = -1; // actual (last occupied)
  std::int64_t capacity; // max

  bool isEmpty() {
    return size == -1;
  }

public:
  DynamicArray(); // default ctor
  DynamicArray(std::int64_t capacity); // parametrized ctor
  DynamicArray(DynamicArray& other);
  ~DynamicArray(); // destructor

  void push_back(float x);
  float add(std::int64_t idx1, std::int64_t idx2);
  float max();
  float min();
  void clear(); // deallocate the data
  void reinitialize(); // restore to default
  void printData();

  float operator[](std::int64_t idx);
  float operator()();
};

#endif // DYN_ARR_H
