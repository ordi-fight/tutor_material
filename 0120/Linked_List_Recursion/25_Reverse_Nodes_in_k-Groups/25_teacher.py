from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        cur = head
        for i in range(k):
            if cur == None:
                return head
            cur = cur.next
        
        prev = None
        cur = head
        for _ in range(k):
            nextNode = cur.next
            cur.next = prev
            prev = cur
            cur = nextNode
        
        head.next = self.reverseKGroup(cur, k)

        return prev