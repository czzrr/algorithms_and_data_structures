#include "LinkedList.hpp"
#include "Node.hpp"
#include <iostream>

using namespace std;

int main() {

  LinkedList<int> list = LinkedList<int>();
  cout << "Printing the empty list:\n";
  cout << list << "\n";
  list.add(2);
  list.add(3);
  list.add(5);
  list.add(7);
  list.add(11);
  cout << "Adding the following values to the list: 2, 3, 5, 7, 11:\n";
  cout << list << "\n";
  cout << "Printing list after removing 5:\n";
  list.remove(5);
  cout << list << "\n";
  cout << "Element at index 2\n";
  cout << list.get(2) << "\n";
  cout << "Removing element at index 2:\n";
  list.remove_at(2);
  cout << list << "\n";
  cout << "Creating a copy of the list via constructor:\n";
  LinkedList<int> list2(list);
  cout << list2 << "\n";
  cout << "Creating a copy of the list via assignment:\n";
  LinkedList<int> list3;
  list3 = list2;
  cout << list3 << "\n";
  cout << "Adding -1, -2, -3, respectively, to the three lists:\n";
  list.add(-1);
  list2.add(-2);
  list3.add(-3);
  cout << list << "\n";
  cout << list2 << "\n";
  cout << list3 << "\n";
  // cout << "Trying to access index 7 of the first list:\n";
  // list.get(7);
}
