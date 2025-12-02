from typing import Optional
# Given head, the head of a linked list, determine if the linked list has a cycle in it.

# There is a cycle in a linked list if there is some node in the list that can be reached again
# by continuously following the next pointer. Internally, pos is used to denote the index of the
# node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

# Return true if there is a cycle in the linked list. Otherwise, return false.


class ListNode:
    # Definition for singly-linked list.
    def __init__(self, x):
        self.val = x
        self.next: Optional[ListNode] = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast = head
        while fast and fast.next:
            head = head.next  # type: ignore
            fast = fast.next.next
            if head == fast:
                return True
        return False


########################################################
# build nodes for cycle test
n1 = ListNode(3)
n2 = ListNode(2)
n3 = ListNode(0)
n4 = ListNode(-4)

# link them into a list: 3 -> 2 -> 0 -> -4
n1.next = n2
n2.next = n3
n3.next = n4

# create a cycle: last node (-4) points back to node 2
n4.next = n2

sol = Solution()
print("Has cycle:", sol.hasCycle(n1))  # expect True

########################################################
# build nodes for non cycle test
n5 = ListNode(64)
n6 = ListNode(256)
n5.next = n6

print("Has cycle:", sol.hasCycle(n5))  # expect False
