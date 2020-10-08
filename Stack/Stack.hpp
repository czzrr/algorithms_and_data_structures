#ifndef STACK_H
#define STACK_H

#include <forward_list>
#include <iostream>

using namespace std;

/* Stack implementation using linked list */
template<typename T>
class Stack {
private:
  forward_list<T> stack;
public:
  Stack();
  Stack(const Stack<T>& s);
  Stack<T>& operator=(const Stack<T>& s);
    
  T peek() const;
  T pop();
  void push(T);
  bool empty() const;
  
  forward_list<T> get_list() const;

  friend std::ostream& operator<<(std::ostream& out, const Stack<T>& stack) {
    if (stack.empty())
      return out << "[]";

    forward_list<T> list = stack.stack;

    out << "[";
    auto elem = list.begin();
    out << list.front();
    elem++;
    for (auto iter = ++list.begin(); iter != list.end(); iter++)
      out << ", " << *iter;
    out << "]";

    return out;
  }
};

template<typename T>
Stack<T>::Stack() {
  stack = forward_list<T>();
}

template <typename T>
Stack<T>::Stack(const Stack<T>& s) {
  this->stack = s.stack;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s) {
  this->stack = s.stack;
  return *this;
}

template<typename T>
T Stack<T>::peek() const {
  if (empty())
    throw std::runtime_error("Stack is empty");
  return stack.front();
}

template<typename T>
T Stack<T>::pop() {
  if (empty())
    throw std::runtime_error("Stack is empty");
  T top = stack.front();
  stack.pop_front();
  return top;
}

template <typename T>
void Stack<T>::push(T t) {
  stack.push_front(t);
}

template <typename T>
bool Stack<T>::empty() const {
  return stack.empty();
}

#endif
