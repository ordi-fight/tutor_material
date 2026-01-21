from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 == None or list2 == None:
          
          if list1:
            return list1
          elif list2:
            return list2
          return None
        
        elif list1.val < list2.val:
            start = list1
            cur1 = list1
            cur2 = list2
        elif list1.val >= list2.val:
            start = list2
            cur1 = list2
            cur2 = list1
        is_cur1_change  = True
        while cur1 != None:
            if is_cur1_change:
                next_node1 = cur1.next
            if cur2:
              
              next_node2 = cur2.next
            
            if next_node1:
                if cur2 :
                  
                    if cur1.val <= cur2.val < next_node1.val:
                        cur1.next = cur2
                        cur2.next = next_node1
                        cur2 = next_node2
                        is_cur1_change = False
                    if cur2.val >= next_node1.val:
                        cur1 = next_node1
                        is_cur1_change = True
                if not cur2:
                  break
            elif not next_node1:

                if cur2:

                    cur1.next = cur2
                
            
        return start
def listgeneration(node):

        if isinstance(node,ListNode):
            if node == None:
                lst = []
            else:
                lst = [node.val]
            lst.extend(listgeneration(node.next))

            return lst
            
        else:
          
          return []
s = Solution()
print(listgeneration(s.mergeTwoLists(ListNode(1,ListNode(2,ListNode(4,None))),ListNode(1,ListNode(3,ListNode(4,None))))))