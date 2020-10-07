#ifndef DEQUE_H
#define DEQUE_H

#include <list>

template<typename T>
class Deque {
  std::list<T> deque;
public:
  T get_front();
  T get_back();
  T remove_front();
  T remove_back();
  void insert_front(T);
  void insert_back(T);
  bool empty();

  std::list<T> get_list();
  
  std::ostream& operator<<(std::ostream& out);
};

template<typename T>
T Deque<T>::get_front() {
  return deque.front();
}

template<typename T>
T Deque<T>::get_back() {
  return deque.back();
}

template<typename T>
T Deque<T>::remove_front() {
  T front = get_front();
  deque.pop_front();
  return front;
}

template<typename T>
T Deque<T>::remove_back() {
  T back = get_back();
  deque.pop_back();
  return back;
}

template<typename T>
void Deque<T>::insert_front(T elem) {
  deque.push_front(elem);
}

template<typename T>
void Deque<T>::insert_back(T elem) {
  deque.push_back(elem);
}

template<typename T>
std::list<T> Deque<T>::get_list() {
  return deque.list;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Deque<T>& deque) {
  if (deque.empty())
    out << "[]";
  out << "[";
  std::list<T> lst = deque.get_list(); 
  for (auto x : lst)
    out << x << ", ";
  out << "]";
  return out;
}

#endif
