from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def match(node):
  if node == None:
    return None
  return node.val
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        index = 0
        next_group_1 = []
        length  = 0
        def count_length(node):
          nonlocal length
          if node == None:
  
              return 0
          
          length += 1
  
          count_length(node.next)
  
          return length
        length = count_length(head)
        def recur(head):
          
          nonlocal index
          # before return
          index += 1
          
          # base case
          if head == None :
            if (length % k) == 0:
              next_group_1.append(head)
            return index - 1 
          # recur
          index  = recur(head.next)
          print(index)
          #after return
          if index == (length // k)*k + 1:
              
              next_group_1.append(head)
              
          elif 0 < index <= (length // k)*k :
            if (index % k) == 0:
                
                next_group_1 .append(head)
               
            elif (index % k) == 1:
                next_node = head.next
                next_node.next = head
                head.next = next_group_1.pop(0)
                
            else:
                next_node = head.next
                next_node.next = head
                
          
          return index - 1
        
        def Listnode_format(node):
  
            if node == None:
    
              return None
    
            return f"ListNode({node.val},{Listnode_format(node.next)})"
        if k == 1:
          return Listnode_format(head)
        else:
          recur(head)
          return Listnode_format(next_group_1[0] if next_group_1 else None)
      
             
    
s = Solution()
print(s.reverseKGroup(ListNode(1,ListNode(2,ListNode(3,ListNode(4,ListNode(5,None))))),1))

        
