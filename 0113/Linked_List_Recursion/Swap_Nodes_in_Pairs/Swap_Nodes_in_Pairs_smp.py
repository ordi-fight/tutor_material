# how to simplify if

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        pre = None
        cur = head
        cnt = 1
        output = cur
        while cur != None:
            next_node = cur.next
            
            if cnt % 2 == 0:
                cur.next = pre
            elif cnt % 2 != 0:
                # simplify if 
                if cur.next == None or cur.next.next == None:
                    cur.next = None
                elif cur.next.next.next == None:
                    cur.next = cur.next.next
                elif cur.next.next.next != None:
                    cur.next = cur.next.next.next
            if cnt == 2:
                output = cur
            pre = cur
            cur = next_node
            cnt += 1 
        return output