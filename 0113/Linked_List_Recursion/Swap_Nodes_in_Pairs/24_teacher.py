# Definition for singly-linked list.
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head
        
        first_node = head
        second_node = head.next

        first_node.next = self.swapPairs(second_node.next)
        second_node.next = first_node

        return second_node


class Solution1:
    def rec(self, node, cur):
        if node == None or node.next == None:
            return node
        
        return_node = self.rec(node.next, 1 - cur)

        if cur == 0:
            second_node = return_node.next
            node.next = second_node
            return_node.next = node
            return return_node
        else:
            node.next = return_node
            return node

    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.rec(head, 0)
