from typing import Optional


class ListNode:
    # Definition for singly-linked list.
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()         # fake head ptr to simplify list building
        current = dummy            # pointer to build the result list
        carry = 0                  # carry starts at 0

        # loop while there is something to process
        while l1 or l2 or carry:
            # get current values or 0 if the list already ended
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0

            # add them plus carry
            total = v1 + v2 + carry

            # new digit is total % 10, new carry is total // 10
            carry = total // 10
            digit = total % 10

            # create new node with this digit
            current.next = ListNode(digit)
            current = current.next

            # move pointers forward if they still exist
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        # result starts at dummy.next (skip the fake head)
        return dummy.next

