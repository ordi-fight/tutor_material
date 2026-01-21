from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def __init__(self):
        self.length = 0
        self.node_index = 0
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        def recur(head):
            # before return
            self.node_index += 1
            
            # base case
              
            if self.length % 2 == 0 and self.node_index > (self.length) // 2:
                
                return True , head
            elif self.length % 2 != 0 and self.node_index > (self.length) // 2:
                
                return True , head.next
            elif head == None or head.next == None: 
              return True , None
            # recur

            res , after_N_node = recur(head.next)
            
            # after return

            if not res:
                if after_N_node : after_N_node = after_N_node.next
                return False , after_N_node
            
            if head.val == after_N_node.val:
                
                if after_N_node : after_N_node = after_N_node.next
                return True , after_N_node
            if after_N_node : after_N_node = after_N_node.next
            return False , after_N_node
                
        self.count_length(head)
        return recur(head)[0]
    def count_length(self,node):

        if node == None:

            return 0
        
        self.length += 1

        self.count_length(node.next)

        return self.length