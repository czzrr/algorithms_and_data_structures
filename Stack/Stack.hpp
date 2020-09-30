#ifndef STACK_H
#define STACK_H

#include "../LinkedList/LinkedList.hpp"
#include <iostream>

template<typename T>
class Stack {
private:
  LinkedList<T> stack;
public:
  Stack();
  ~Stack();
  Stack(const Stack<T>& s);
  Stack<T>& operator=(const Stack<T>& s);
    
  T peek();
  T pop();
  void push(T);
  bool empty();
  
  LinkedList<T> get_list() const;

  std::ostream& operator<<(std::ostream& out);
};

// Implementation

template<typename T>
Stack<T>::Stack() {
  stack = LinkedList<T>();
}

template<typename T>
Stack<T>::~Stack() {
  
}

template <typename T>
Stack<T>::Stack(const Stack<T>& s) {
  this->stack = s.get_list();
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s) {
  this->stack = s.get_list();
  return *this;
}

template<typename T>
T Stack<T>::peek() {
  if (empty())
    throw "Stack is empty";
  Node<T>* head = stack.get_head();
  T peek = head->get_value();
  return peek;
}

template<typename T>
T Stack<T>::pop() {
  if (empty()) {
    std::cout << "Stack is empty\n";
    throw "Stack is empty";
  }
  T peek_elem = peek();
  Node<T>* removed = stack.remove(peek_elem);
  delete removed;
  return peek_elem;
}

template <typename T>
void Stack<T>::push(T t) {
  stack.insert(t);
}

template <typename T>
bool Stack<T>::empty() {
  return stack.empty();
}

template <typename T>
LinkedList<T> Stack<T>::get_list() const {
  return stack;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, Stack<T>& stack) {
  LinkedList<T> list = stack.get_list();
  return out << list;
  return out << list;
}

#endif
