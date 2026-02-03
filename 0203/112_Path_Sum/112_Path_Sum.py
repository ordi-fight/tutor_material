from typing import Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
      
      
      def is_leaf(node):
        
        if node != None and node.right == None and node.left == None:
          
          return True
        
        return False
        
      def dfs(node , summation):
        if node == None :
          
          return False
          
        summation += node.val
        
        if is_leaf(node) and summation == targetSum:
          
          return True
        elif is_leaf(node) and summation != targetSum:
          
          return False
        
        if  dfs(node.left , summation):
          
          return True
        
        if dfs(node.right , summation):
          
          return True
        
        return False
        
      return dfs(root , 0)
      
      

            
    
        
        
        
        