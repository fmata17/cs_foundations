// TODO transform from single to double node usage
#pragma once
// SinglyLinkedStack.hpp

template <typename Type>
class LinkedList
{
private:
  struct nodeType
  {
    nodeType *next;
    Type data;
    nodeType(Type val) : next(nullptr), data(val) {}
  };

  nodeType *head;
  int size;

public:
  // constructors
  LinkedList() : head(nullptr), size(0) {}
  LinkedList(Type const data[], int size);

  void push(Type const data);
  void push(Type const data[], int size);

  // TODO implement the following methods with adequate error mitigation
  // void push(LinkedList *list);
  // Type pop();
  // bool isFull();

  int getSize() const;
  void print() const;

  ~LinkedList();
};

/*
 * Template definitions here to avoid linker errors
 */
#include <iostream>

template <typename Type>
LinkedList<Type>::LinkedList(Type const data[], int size)
    : head(nullptr), size(0)
{
  for (int i = 0; i < size; ++i)
  {
    push(data[i]);
  }
}

template <typename Type>
void LinkedList<Type>::push(Type const data)
{
  if (head == nullptr)
  {
    head = new nodeType(data);
    ++size;
  }
  else
  {
    nodeType *newNode = new nodeType(data);

    newNode->next = head;
    head = newNode;

    ++size;
  }
}

template <typename Type>
void LinkedList<Type>::push(Type const data[], int size) // O(n)?
{
  for (int i = 0; i < size; ++i)
  {
    push(data[i]);
  }
}

template <typename Type>
int LinkedList<Type>::getSize() const { return size; }

template <typename Type>
void LinkedList<Type>::print() const
{
  nodeType *curr = head;
  while (curr != nullptr)
  {
    std::cout << curr->data << " ";
    curr = curr->next;
  }
  std::cout << std::endl;
}

template <typename Type>
LinkedList<Type>::~LinkedList()
{
  while (head != nullptr)
  {
    nodeType *temp = head;
    head = head->next;
    delete temp;
  }
}
