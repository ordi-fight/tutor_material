from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    
    def recur(self,head,val):
        if head == None or head.next == None:

            return head
        
        end = self.recur(head.next,val)
        
        if head.next.val == val:
            head.next = head.next.next
        return head
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        node1 = self.recur(head,val)
        if node1 == None:
            return None 
        elif node1.val == val:

            return node1.next
        else:

            return node1 

         

        


        