#include "Stack.hpp"
#include <iostream>

using namespace std;

int main() {
  Stack<int> stack = Stack<int>();
  stack.push(3);
  stack.push(7);
  stack.push(11);
  //stack.print();
  cout << stack.peek() << "\n";
  cout << stack << "\n";
  stack.pop();
  cout << stack << "\n";
  stack.push(37);
  cout << stack << "\n";
}
