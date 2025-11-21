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

  // push_front(val),
  // front() - получить нулевой элемент, 
  // back() - получить последний элемент, insert(idx, val), 
  // delete(idx),
  // erase_after(idx) - удалить все после элемента idx (тебя должен капасити остаться тот же, в то время как элементов для доступа меньше)
    // Было 10 элементов, капасити 15
    // Erase_after(5)
    // Остаются первые 6, капасити также 15, размер 6
  // increase_capacity(newCapacity), //Надо сдвигать элементы массива, стоящие правее data[idx] вправо(Без этого, это не инсерт, а replace)
  // decrease_capacity(newCapacity) //новая вместимость может быть меньше количества элементов 

};

#endif // DYN_ARR_H
