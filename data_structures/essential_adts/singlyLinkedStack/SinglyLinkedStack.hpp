#pragma once
#include <iostream>
// SinglyLinkedStack.hpp

template <typename Type>
class SinglyLinkedStack
{
public:
  SinglyLinkedStack() : head(nullptr), size(0) {}          // default constructor
  SinglyLinkedStack(Type const data[], int size);          // list traversal copy constructor
  SinglyLinkedStack(SinglyLinkedStack<Type> &LinkedStack); // SinglyLinkedStack traversal copy constructor
                                                           // reverses list order as it created a stack from a stack

  void push(Type const data);                      // default push
  void push(Type const data[], int const size);    // list traversal push
  void push(SinglyLinkedStack<Type> &LinkedStack); // SinglyLinkedStack traversal push
                                                   // reverses list order as it pushes from a stack

  Type pop();
  Type peek() const;
  int getSize() const;
  bool isEmpty() const;
  void print() const;

  ~SinglyLinkedStack();

private:
  struct nodeType
  {
    nodeType *next;
    Type data;
    nodeType(Type val) : next(nullptr), data(val) {}
  };

  nodeType *head;
  int size;
};

/*
 * Template definitions here to avoid linker errors
 */

template <typename Type>
inline SinglyLinkedStack<Type>::SinglyLinkedStack(Type const data[], int size)
    : head(nullptr), size(0)
{
  for (int i = 0; i < size; ++i)
  {
    push(data[i]);
  }
}

template <typename Type>
inline SinglyLinkedStack<Type>::SinglyLinkedStack(SinglyLinkedStack<Type> &LinkedStack)
    : head(nullptr), size(0)
{
  nodeType *curr = LinkedStack.head;
  while (curr != nullptr)
  {
    push(curr->data);
    curr = curr->next;
  }
}

template <typename Type>
inline void SinglyLinkedStack<Type>::push(Type const data)
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
inline void SinglyLinkedStack<Type>::push(Type const data[], int const size) // O(n)?
{
  for (int i = 0; i < size; ++i)
  {
    push(data[i]);
  }
}

template <typename Type>
inline void SinglyLinkedStack<Type>::push(SinglyLinkedStack<Type> &LinkedStack)
{
  nodeType *curr = LinkedStack.head;
  while (curr != nullptr)
  {
    push(curr->data);
    curr = curr->next;
  }
}

template <typename Type>
inline Type SinglyLinkedStack<Type>::pop()
{
  Type data = head->data;
  head = head->next;
  return data;
}

template <typename Type>
inline Type SinglyLinkedStack<Type>::peek() const { return head->data; }

template <typename Type>
inline int SinglyLinkedStack<Type>::getSize() const { return size; }

template <typename Type>
inline bool SinglyLinkedStack<Type>::isEmpty() const
{
  return size == 0;
}

template <typename Type>
inline void SinglyLinkedStack<Type>::print() const
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
inline SinglyLinkedStack<Type>::~SinglyLinkedStack()
{
  while (head != nullptr)
  {
    nodeType *temp = head;
    head = head->next;
    delete temp;
  }
}
