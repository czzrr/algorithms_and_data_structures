#ifndef NODE_H
#define NODE_H

/* -- Declaration -- */

template<typename T>
class Node {
private:
  T value;  
  Node<T>* next;
public:
  Node(T value);
  Node();
  Node<T>(const Node<T>& a);
  Node<T>& operator=(const Node<T>& a);
  T get_value();
  void set_value(T value);
  Node<T>* get_next();
  void set_next(Node<T>* next);
};

/* -- Implementation -- */

template<typename T>
Node<T>::Node(T initial_value): value(initial_value), next(nullptr) {};

template<typename T>
Node<T>::Node(): next(nullptr) {};

template<typename T>
T Node<T>::get_value() {
  return this->value;
}

template<typename T>
void Node<T>::set_value(T value) {
  this->value = value;
}

template<typename T>
void Node<T>::set_next(Node<T>* next) {
  this->next = next;
}

template<typename T>
Node<T>* Node<T>::get_next() {
  return next;
}

#endif
