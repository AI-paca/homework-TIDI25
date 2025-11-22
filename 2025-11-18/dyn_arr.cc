#include "dyn_arr.h"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

DynamicArray::DynamicArray() {
  this->capacity = 8;
  this->data = new float[this->capacity];
}

DynamicArray::DynamicArray(std::int64_t capacity) {
  // check if user is dumb
  if (capacity < 1) {
    throw std::invalid_argument("Capacity < 1"); // https://en.cppreference.com/w/cpp/error/exception.html
    // std::exception like an animal
    // std::invalid_argument like a dog (heir of animal)
  }
  this->capacity = capacity;
  this->data = new float[this->capacity];
}

DynamicArray::DynamicArray(DynamicArray& other) {
  this->size = other.size;
  this->capacity = other.capacity;
  this->data = new float[this->capacity]; // (*this).data

  for (int i = 0; i <= size; ++i) {
    this->data[i] = other.data[i];
  }
}

DynamicArray::~DynamicArray() {
  // deallocate if allocated
  if (this->data) {
    delete[] this->data;
  }
}

void DynamicArray::push_back(float x) {
  // reallocate memory
  // increase capacity
  // copy data
  // dealloc old
  // assign new to old
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    float* tempArray = new float[newCapacity];
    for (int i = 0; i < capacity; ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }
  data[++size] = x;
  // data[size + 1] = x;
  // ++size;
}

float DynamicArray::add(std::int64_t idx1, std::int64_t idx2) {
  if (idx1 > size || idx2 > size || idx1 < 0 || idx2 < 0) {
    throw std::invalid_argument("idx1 or idx2 out of range");
  }
  return data[idx1] + data[idx2];
}

float DynamicArray::max() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  float currentMax = -1e+38; // -1 * 10^38
  // float currentMax = std::numeric_limits<float>::lowest();
  for (int i = 0; i <= size; ++i) {
    if (data[i] >= currentMax) {
      currentMax = data[i];
    }
  }
  return currentMax;
}

float DynamicArray::min() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  float currentMin = 1e+38; // -1 * 10^38
  // float currentMin = std::numeric_limits<float>::max();
  for (int i = 0; i <= size; ++i) {
    if (data[i] <= currentMin) {
      currentMin = data[i];
    }
  }
  return currentMin;
}

void DynamicArray::clear() {
  if (this->data) {
    delete[] this->data;
    this->data = nullptr;
  }
  size = -1;
  capacity = 8;
}

void DynamicArray::reinitialize() {
  clear();
  data = new float[capacity](); // init with zeros
}

void DynamicArray::printData() {
  if (isEmpty()) {
    return;
  }
  for (int i = 0; i <= size; ++i) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}

float DynamicArray::operator[](std::int64_t idx) {
  if (isEmpty() || idx < 0 || idx > size) {
    throw std::invalid_argument("Out of range");
  }
  return data[size - idx]; // Arabic operator[]
  // return data[idx];     // European operator[]
}

float DynamicArray::operator()() {
  if (isEmpty()) {
    return 0;
  }
  float sum = 0;
  for (int i = 0; i <= size; ++i) {
    sum += data[i];
  }
  return sum;
}

////////////////////////////////////////////// HW

  void DynamicArray::push_front(float x){
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    float* tempArray = new float[newCapacity];
    for (int i = 0; i < capacity; ++i) {
      tempArray[i+1] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
    data[0] = x;
    ++size;
    return;
  }
  else {
    float temp = data[0];
    for (int i = 0; i <= size; ++i) {
      std::swap(data[i+1], temp);
    }
    data[0] = x;
    ++size;
    return;
  }
  }

  float DynamicArray::front(){
    if (isEmpty()) {
      throw std::invalid_argument("Empty array");
    }
    return data[0];
  }

  float DynamicArray::back(){
    if (isEmpty()) {
      throw std::invalid_argument("Empty array");
    }
    return data[size];
  }

  void DynamicArray::insert(std::int64_t idx, float val){
    if (idx < 0 || idx > size + 1) {
      throw std::invalid_argument("Index out of range");
    }

    //сдвигать элементы массива, стоящие правее data[idx] вправо(Без этого, это не инсерт, а replace)
    if (size + 1 >= capacity) {
      std::int64_t newCapacity = capacity * 2;
      float* tempArray = new float[newCapacity];
      for (int i = 0; i < idx; ++i) {
        tempArray[i] = data[i];
      }
      tempArray[idx] = val;
      for (int i = idx; i <= size; ++i) {
        tempArray[i + 1] = data[i];
      }
      delete[] data;
      data = tempArray;
      capacity = newCapacity;
      ++size;
      return;
    }
    else {
      float temp = data[idx];
      data[idx] = val;
      for (int i = idx; i <= size; ++i) {
        std::swap(data[i + 1], temp);
      }
      ++size;
      return;
    }
  }

  void DynamicArray::rename_it_latter_delete(std::int64_t idx){
    if (idx < 0 || idx > size) {
      throw std::invalid_argument("Index out of range");
    }
    //сдвигать элементы массива, стоящие правее data[idx] влево
    for (int i = idx; i < size; ++i) {
      data[i] = data[i + 1];
    }
    --size;
  }

  void DynamicArray::erase_after(std::int64_t idx){
    if (idx < 0 || idx > size) {
      throw std::invalid_argument("Index out of range");
    }
    for (int i = idx + 1; i <= size; ++i) {
      data[i] = 0; // optional
      --size;
    }
    //удалить все после элемента idx (тебя должен капасити остаться тот же, в то время как элементов для доступа меньше)
    // Было 10 элементов, капасити 15
    // Erase_after(5)
    // Остаются первые 6, капасити также 15, размер 6
  } 

  void DynamicArray::increase_capacity(std::int64_t newCapacity){
    if (newCapacity <= capacity) {
      throw std::invalid_argument("New capacity must be greater than current capacity");
    }
    float* tempArray = new float[newCapacity];
    for (int i = 0; i <= size; ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }

  void DynamicArray::decrease_capacity(std::int64_t newCapacity){ 
    if (newCapacity < 0) {
      throw std::invalid_argument("New capacity must be greater than or equal to number of elements");
    }
    //новая вместимость может быть меньше количества элементов 
    float* tempArray = new float[newCapacity];
    for (int i = 0;(i <= size) && (i < newCapacity); ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
    if (size >= newCapacity) {
      size = newCapacity - 1;
    }
  }