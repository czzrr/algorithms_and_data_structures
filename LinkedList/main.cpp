#include "LinkedList.hpp"
#include "Node.hpp"
#include <iostream>

using namespace std;

int main() {
  Node<int> node1 = Node<int>(17);
  Node<int> node2 = Node<int>(5);
  Node<int> node3 = Node<int>(37);
  cout << "Printing nodes with values 17, 5, 37:\n";
  cout << node1.get_value() << " ";
  cout << node2.get_value() << " ";
  cout << node3.get_value() << "\n";

  LinkedList<int> list = LinkedList<int>();
  list.insert(17);
  list.insert(5);
  list.insert(0);
  list.insert(37);
  cout << "Printing the list 37, 0, 5, 17:\n";
  cout << list << "\n";
  LinkedList<int> list2(list);
  cout << list2 << "\n";
  LinkedList<int> list3;
  list3 = list2;
  cout << list3 << "\n";
  list.insert(-1);
  list2.insert(-2);
  list3.insert(-3);
  cout << list << "\n";
  cout << list2 << "\n";
  cout << list3 << "\n";
  // cout << "Printing list after removing 5:\n";
  // Node<int>* removed = list.remove(5); // returns node with value 5
  // cout << list << "\n";
  // list.insert(41);
  // cout << "Printing list after adding 41:\n";
  // cout << list << "\n";
  // cout << "Printing list after removing -3:\n";
  // list.remove(-3); // returns nullptr
  // cout << list << "\n";
  // delete removed; // remember to delete removed node!
}
