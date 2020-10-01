#include "Stack.hpp"
#include <iostream>

using namespace std;

int main() {
  Stack<int> stack = Stack<int>();
  cout << "Printing the empty stack:\n";
  cout << stack << "\n";
  try {
    cout << "Trying to peek empty stack:\n";
    cout << stack.peek() << "<n";
  } catch (std::runtime_error e) {
    cout << "Exception occurred: " << e.what() << "\n";
  }
  cout << "Pushing 3, 7, 11:\n";
  stack.push(3);
  stack.push(7);
  stack.push(11);
  cout << stack << "\n";
  cout << "Peeking:\n";
  cout << stack.peek() << "\n";
  cout << "Popping:\n";
  stack.pop();
  cout << stack << "\n";
  cout << "Pushing 37:\n";
  stack.push(37);
  cout << stack << "\n";
  cout << "Popping three times:\n";
  for (int i = 0; i < 3; i++) {
    stack.pop();
    cout << stack << "\n";
  }
  
  try {
    cout << "Trying to pop empty stack:\n";
    cout << stack.pop() << "<n";
  } catch (std::runtime_error e) {
    cout << "Exception occurred: " << e.what() << "\n";
  }
}
