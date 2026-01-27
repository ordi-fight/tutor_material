from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def count_lengh(self,node , length):
        if node == None:
          return length;
        final_length = self.count_lengh(node.next , length + 1)
        return final_length
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        
      final_length = self.count_lengh(head , 0)
      
      first_node = ListNode(head.val, None) if head else None
      
      
      def recur(head,index,f_node):
        nonlocal final_length , first_node

        # edge input
        
        if head == None :
          
          treenode = None
          
          return  treenode
        # first_node
            
        if index == 1 and (final_length == 1 or final_length == 2):
          
            first_node = None
        elif index <  (final_length + 1) // 2:
          if  index == (final_length + 1) // 2 - 1:
            
            f_node.next = None
          else:

            f_node.next = ListNode(head.next.val ,None) 
        if f_node :
          print(f"index = {index}, final_length = {final_length} , {ListNode_format(first_node)}")
        if not f_node:
          print(ListNode_format(first_node))
        # base case 
        
        if head.next == None :
          
          
          treenode = TreeNode(head.val , None , None)
          
          return treenode
          
        elif index == (final_length + 1) // 2:
        
          treenode = TreeNode(head.val , None , None)
          
          treenode.right = self.sortedListToBST(head.next) 
          
          treenode.left = self.sortedListToBST(first_node) 
          
          return treenode
        
        # recur  
          
        treenode = recur(head.next , index + 1 , f_node.next)
    
        return treenode
      
      return recur(head,1 , first_node)
def TreeNode_format(node):
 
    if node == None:
      return None
      
    left = TreeNode_format(node.left) if node.left else None
    right = TreeNode_format(node.right) if node.right else None
    
    return f"TreeNode({node.val},{left},{right})"
def ListNode_format(node):
  
    if node == None:
      return None
    
    return f"ListNode({node.val} , {ListNode_format(node.next)})"
s = Solution()

print(TreeNode_format(s.sortedListToBST(ListNode(-10,ListNode(-3,ListNode(0,ListNode(5,ListNode(9,ListNode(10,None)))))))))
      
    
    