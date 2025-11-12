#include <iostream>
#include "SinglyLinkedStack.hpp"
using namespace std;

int main()
{
  int intNums[] = {1, 2, 3};
  float floatNums[] = {1, 2, 3};

  // default constructors
  SinglyLinkedStack<int> stack1;
  for (int num : intNums)
    stack1.push(num);

  stack1.print();

  // list traversal constructor
  SinglyLinkedStack<float> stack2(floatNums, 3);
  stack2.push(floatNums, 3);
  stack2.print();

  // SinglyLinkedStack traversal constructor
  SinglyLinkedStack<int> stack3(stack1);
  stack3.push(stack1);
  stack3.print();
  cout << stack3.peek() << endl;

  cout << stack1.isEmpty() << endl;
  cout << stack3.getSize() << endl;

  return 0;
}
