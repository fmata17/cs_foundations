#include <iostream>
#include "SinglyLinkedStack.hpp"

int main ()
{
  LinkedList<int> list1;
  list1.push(1);
  list1.push(2); 
  list1.push(3);
  
  list1.print();

  int nums1[] = {4, 5, 6};
  list1.push(nums1, 3);

  list1.print();

  float nums2[] = {100.1, 200.2, 300.3};

  LinkedList<float> list2(nums2, 3);

  list2.print();

  float nums3[] = {400.4, 500.5, 600.6};

  list2.push(nums3, 3);

  list2.print();

  return 0;
}
