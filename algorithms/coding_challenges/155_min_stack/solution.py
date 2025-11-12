# Design a stack class that supports the push, pop, top, and getMin operations.

# MinStack() initializes the stack object.
# void push(int val) pushes the element val onto the stack.
# void pop() removes the element on the top of the stack.
# int top() gets the top element of the stack.
# int getMin() retrieves the minimum element in the stack.

# Each function should run in O(1) time.
from typing import Optional


class MinStack():
    class Node:
        def __init__(self, val: int, currMin: int):
            self.data = val
            self.currMin = currMin
            self.next: Optional["MinStack.Node"] = None

    def __init__(self):
        self.topNode = None
        self.height = 0

    def push(self, val: int) -> None:
        if self.topNode == None:
            self.topNode = self.Node(val, val)
            self.height += 1
        else:
            temp = self.Node(val, min(self.topNode.currMin, val))
            temp.next = self.topNode
            self.topNode = temp
            self.height += 1

    def pop(self) -> None:
        temp = self.topNode
        if self.topNode:
            self.topNode = self.topNode.next
        del temp
        self.height -= 1

    def top(self) -> int:
        if not self.topNode:
            raise IndexError("Empty Stack")
        return self.topNode.data

    def getMin(self) -> int:
        if not self.topNode:
            raise IndexError("Empty Stack")
        return self.topNode.currMin
