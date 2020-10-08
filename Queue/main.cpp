#include "Queue.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  Queue<int> q;
  
  cout << "Empty queue:\n";
  cout << q << "\n\n";

  cout << "Enqueueing 3\n";
  q.enqueue(3);
  cout << q << "\n\n";

  cout << "Enqueueing 5\n";
  q.enqueue(5);
  cout << q << "\n\n";

  cout << "Enqueueing 7, 11, 19\n";
  q.enqueue(7);
  q.enqueue(11);
  q.enqueue(19);
  cout << q << "\n\n";

  cout << "Enqueueing 29, 31\n";
  q.enqueue(29);
  q.enqueue(31);
  cout << q << "\n\n";

  cout << "Trying to enqueue 1\n";
  try {
    q.enqueue(1);
    cout << q << "\n\n";
  } catch(std::runtime_error e) {
    cout << e.what() << "\n\n";
  }

  cout << "Trying to enqueue 4\n";
  try {
    q.enqueue(4);
    cout << q << "\n\n";
  } catch(std::runtime_error e) {
    cout << e.what() << "\n\n";
  }

  cout << "Dequeueing until empty\n";
  while (!q.is_empty()) {
    q.dequeue();
    cout << q << "\n";
  }

  cout << "Enqueueing n^(n + 2) until full\n";
  for (int i = 0; !q.is_full(); i++) {
    q.enqueue((int) pow(i, i + 2));
    cout << q << "\n";
  }
}
