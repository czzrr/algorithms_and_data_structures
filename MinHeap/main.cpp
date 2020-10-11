#include <iostream>
#include "MinHeap.hpp"

using namespace std;

int main() {
  MinHeap heap = MinHeap(16);
  cout << "Empty min heap:\n";
  cout << heap << "\n";

  cout << "Inserting 7:\n";
  heap.insert(7);
  cout << heap << "\n";

  cout << "Inserting 9:\n";
  heap.insert(9);
  cout << heap << "\n";

  cout << "Inserting 3:\n";
  heap.insert(3);
  cout << heap << "\n";

  cout << "Inserting 5:\n";
  heap.insert(5);
  cout << heap << "\n";

  cout << "Inserting 10:\n";
  heap.insert(10);
  cout << heap << "\n";

  cout << "Inserting 2:\n";
  heap.insert(2);
  cout << heap << "\n";

  cout << "Inserting 6:\n";
  heap.insert(6);
  cout << heap << "\n";
}
