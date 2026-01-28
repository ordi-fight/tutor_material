from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return True
        
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
        prev = None
        curr = slow
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
            
        left, right = head, prev
        while right:
            if left.val != right.val:
                return False
            left = left.next
            right = right.next
            
        return True
    

class Solution2:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        self.left = head
        
        def check(right):
            if not right:
                return True

            res = check(right.next) and (self.left.val == right.val)
            
            self.left = self.left.next
            return res
            
        return check(head)