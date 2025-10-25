#pragma once
#include <iostream>
// SinglyLinkedList.hpp

using namespace std;

template <typename Type>
class SinglyLinkedList
{
public:
  SinglyLinkedList() : head(nullptr), size(0) {}
  void insert(Type const val);
  int getSize();
  void print();
  ~SinglyLinkedList();

private:
  struct Node
  {
    Node *next;
    Type data;
    Node(Type val) : data(val), next(nullptr) {}
  };
  Node *head;
  int size;
};

template <typename Type>
void SinglyLinkedList<Type>::insert(Type const val)
{
  Node *newNode = new Node(val);

  if (head == nullptr)
  {
    head = newNode;
    ++size;
  }

  else
  {
    Node *curr = head;
    while (curr->next != nullptr)
    {
      curr = curr->next;
    }
    curr->next = newNode;
    ++size;
  }
}

template <typename Type>
int SinglyLinkedList<Type>::getSize() { return size; }

template <typename Type>
void SinglyLinkedList<Type>::print()
{
  Node *curr = head;
  while (curr != nullptr)
  {
    std::cout << curr->data << " ";
    curr = curr->next;
  }
  std::cout << std::endl;
}

template <typename Type>
SinglyLinkedList<Type>::~SinglyLinkedList()
{
  while (head != nullptr)
  {
    Node *toDelete = head;
    head = head->next;
    delete toDelete;
  }
}
