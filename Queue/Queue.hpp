#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include <iostream>

template<typename T>
class Queue {
  T* arr;
  int capacity;
  int front;
  int back;
  bool empty;
  bool full;
public:
  Queue();
  void enqueue(T);
  T dequeue();
  T peek() const;
  bool is_empty() const;
  bool is_full() const;

  // Works (why need a new type U?):
  // template <typename U> friend std::ostream& operator<<(std::ostream&, const Queue<U>&);

  // Didn't work:
  // template <T> friend std::ostream& operator<<(std::ostream&, const Queue<T>&);
  
  // I'll just define the friend function within the class
  friend std::ostream& operator<<(std::ostream& out, const Queue<T>& q) {
    // Print queue from front to back
    if (q.is_empty()) {
      out << "[]";
      return out;
    }
    out << "[";
    int f = q.front;
    out << q.arr[f];
    f = (f + 1) % q.capacity;
    while (f != q.back) {
      out << ", " << q.arr[f];
      f = (f + 1) % q.capacity;
    }
    out << "]";
    return out;
  }
};

template<typename T>
Queue<T>::Queue(): arr(new int[8]), capacity(8), front(0), back(0), empty(true), full(false) {}

template<typename T>
void Queue<T>::enqueue(T x) {
  if (is_full())
    throw std::runtime_error("Queue is full");
  if (empty && back == front)
    empty = false;
  arr[back] = x;
  back = (back + 1) % capacity;
  
  if (!empty && back == front)
    full = true;
}

template<typename T>
T Queue<T>::dequeue() {
  if (is_empty())
    throw std::runtime_error("Queue is empty");
  if (full)
    full = false;
  T x = arr[front];
  front = (front + 1) % capacity;
  if (front == back)
    empty = true;
  return x;
}

template<typename T>
T Queue<T>::peek() const {
  if (is_empty())
    throw std::runtime_error("Queue is is_empty");
  T x = arr[front];
  return x;
}

template<typename T>
bool Queue<T>::is_empty() const {
  return empty;
}

template<typename T>
bool Queue<T>::is_full() const {
  return full;
}

#endif
