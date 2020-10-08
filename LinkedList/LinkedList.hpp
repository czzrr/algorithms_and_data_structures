#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.hpp"
#include <iostream>
#include <stdexcept>

template<typename T>
class LinkedList {
private:
  Node<T>* head;
public:
  LinkedList();
  ~LinkedList();
  LinkedList(const LinkedList<T>& a); // copy constructor
  LinkedList<T>& operator=(const LinkedList<T>& a); // copy assignment
  
  void add(T value);
  void add_end(T value);
  T get(int i) const;
  bool contains(T value) const;
  bool remove(T value);
  T remove_at(int i);
  bool empty() const;
  
  std::ostream& operator<< (std::ostream& out);
};

// Implementation

template<typename T>
LinkedList<T>::LinkedList(): head(nullptr) { }

template<typename T>
LinkedList<T>::~LinkedList() {
  Node<T>* current_node = head;
  Node<T>* next_node;
  while (current_node) {
    next_node = current_node->get_next();
    delete current_node;
    current_node = next_node;
  }
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& a): head(nullptr) {
  Node<T>* node = a.head;
  while (node) {
    this->add_end(node->get_value());
    node = node->get_next();
  }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& a) {
  Node<T>* node = a.head;
  while (node) {
    this->add_end(node->get_value());
    node = node->get_next();
  }
    return *this; 
}

template<typename T>
void LinkedList<T>::add(T value) {
  Node<T>* node = new Node<T>(value);
  node->set_next(head);
  head = node;
}

template<typename T>
void LinkedList<T>::add_end(T value) {
  if (!head) {
    head = new Node<T>(value);
  } else {
    Node<T>* node = head;
    while (node->get_next())
      node = node->get_next();
    node->set_next(new Node<T>(value));
  }
}

template<typename T>
T LinkedList<T>::get(int i) const {
  if (i < 0)
    throw std::out_of_range("Index out of range");

  Node<T>* node = head;
  while (i > 0) {
    if (!node)
      throw std::out_of_range("Index out of range");
    node = node->get_next();
    i--;
  }
  return node->get_value();
}

template<typename T>
bool LinkedList<T>::contains(T value) const {
  Node<T>* node = head;
  while (node) {
    if (node->get_value() == value)
      return true;
    node = node->get_next();
  }
  return false;
}

template<typename T>
bool LinkedList<T>::remove(T value) {
  if (!head)
    return false;

  if (head->get_value() == value) {
    Node<T>* temp = head;
    head = head->get_next();
    delete temp;
    return true;
  }

  Node<T>* previous_node = head;
  Node<T>* current_node = head->get_next();
  while (current_node) {
    if (current_node->get_value() == value) {
      previous_node->set_next(current_node->get_next());
      delete current_node;
      return true;
    }
    previous_node = current_node;
    current_node = current_node->get_next();
  }
  return false;
}

template<typename T>
T LinkedList<T>::remove_at(int i) {
  if (i < 0 || empty())
    throw std::out_of_range("Index out of range");

  if (i == 0) {
    Node<T>* temp = head;
    T elem = head->get_value();
    head = head->get_next();
    delete temp;
    return elem;
  }
  i--;
  Node<T>* previous_node = head;
  Node<T>* node = head->get_next();
  while (i > 0) {
    if (!node)
      throw std::out_of_range("Index out of range");
    previous_node = node;
    node = node->get_next();
    i--;
  }
  previous_node->set_next(node->get_next());
  T elem = node->get_value();
  delete node;
  return elem;
}




template<typename T>
bool LinkedList<T>::empty() const {
  return !head;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, LinkedList<T>& list) {
  if (list.empty()) {
    out << "[]";
    return out;
  }
  LinkedList<T> list_copy = list;
  out << "[";
  while (true) {
    out << list_copy.get(0);
    list_copy.remove_at(0);
    if (!list_copy.empty())
      out << ", ";
    else
      break;
  }
  out << "]";    
  return out;
}

#endif
