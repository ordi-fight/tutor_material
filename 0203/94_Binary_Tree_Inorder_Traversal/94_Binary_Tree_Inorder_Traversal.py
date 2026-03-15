from typing import  Optional , List
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
      
      res = []
      
      def is_leaf(node):
        
        if node != None and node.left == None and node.right == None:
          
          return True
          
        return False
      
      def recur(node):
        if node == None:
          
          return
        elif is_leaf(node):
          
          res.append(node.val)
          
          return
        
        recur(node.left)
        
        res.append(node.val)
        
        recur(node.right)
        
        return
      
      recur(root)
      
      return res
      
      
s  = Solution()
print(s.inorderTraversal(TreeNode(1,None,TreeNode(2,TreeNode(3,None,None),None))))
        
        
        
        
      
      