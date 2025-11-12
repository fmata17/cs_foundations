#include "SinglyLinkedList.hpp"

int main () {
  SinglyLinkedList<int> singlyList;

  for (int i = 0; i < 10; ++i) {
    singlyList.insert(i);
  }

  cout << singlyList.getSize() << endl;
  singlyList.print();
  return 0;
}
