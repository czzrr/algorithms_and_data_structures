#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.hpp"
#include <iostream>

template<typename T>
class LinkedList {
private:
  Node<T>* head;
public:
  LinkedList();
  ~LinkedList();
  LinkedList(const LinkedList<T>& a); // copy constructor
  LinkedList<T>& operator=(const LinkedList<T>& a); // copy assignment
  
  Node<T>* get_head() const;
  void set_head(Node<T>* head);
  void insert(T value);
  Node<T>* search(T value);
  Node<T>* remove(T value);
  bool empty();
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
    std::cout << "Deleting node with value " << current_node->get_value() << "\n";
    delete current_node;
    current_node = next_node;
  }
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& a): head(nullptr) {
    Node<T>* current_node = a.get_head();
  while (current_node) {
    this->insert(current_node->get_value());
    current_node = current_node->get_next();
  }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& a) {
  Node<T>* current_node = a.get_head();
  while (current_node) {
    this->insert(current_node->get_value());
    current_node = current_node->get_next();
  }
    return *this; 
}

template<typename T>
Node<T>* LinkedList<T>::get_head() const {
  return head;
}

template<typename T>
void LinkedList<T>::set_head(Node<T>* head) {
  this->head = head;
}

template<typename T>
void LinkedList<T>::insert(T value) {
  Node<T>* node = new Node<T>(value);
  node->set_next(head);
  head = node;
}

template<typename T>
Node<T>* LinkedList<T>::search(T value) {
  Node<T>* current_node = head;
  while (current_node) {
    if (current_node->get_value() == value)
      return current_node;
    current_node = current_node->get_next();
  }
  return nullptr;
}

template<typename T>
Node<T>* LinkedList<T>::remove(T value) {
  if (head)
    return nullptr;

  if (head->get_value() == value) {
    Node<T>* temp = head;
    head = head->get_next();
    return temp;
  }

  Node<T>* previous_node = head;
  Node<T>* current_node = head->get_next();
  
  while (current_node) {
    if (current_node->get_value() == value) {
      previous_node->set_next(current_node->get_next());
      return current_node;
    }
    previous_node = current_node;
    current_node = current_node->get_next();
  }
  return nullptr;
}

template<typename T>
bool LinkedList<T>::empty() {
  return head == nullptr;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, LinkedList<T>& list) {
  if (!list.get_head())
    return out;
  Node<T>* current_node = list.get_head();
  std::cout << "success\n";
  out << "[";
  while (current_node->get_next()) {
    out << current_node->get_value() << ", ";
    current_node = current_node->get_next();
  }
  out << current_node->get_value();
  out << "]";
  return out;
}

#endif
