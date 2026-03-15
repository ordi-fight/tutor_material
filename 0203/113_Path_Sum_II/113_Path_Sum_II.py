from typing import List , Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
      
      
      res = []
      
      def is_leaf(node):
        
        if node != None and node.left == None and node.right == None:
          
          return True
          
        return False
      
      def recur(node, path:list):
        # if we use append to modify path , there are just one variable
        if node == None:
          
          return
        
        if is_leaf(node) :
          
          path = path + [node.val]
          if sum(path) == targetSum:
            
            res.append(path)
            
            return
            
          elif sum(path) != targetSum:
            
            return
        
        recur(node.left , path + [node.val])
        
        recur(node.right , path + [node.val])
        
        
        return
      
      recur(root , [])
      
      
      return res
      

s = Solution()

print(s.pathSum(TreeNode(5,TreeNode(4,TreeNode(11,TreeNode(7,None,None),TreeNode(2,None,None)),None),TreeNode(8,TreeNode(13,None,None),TreeNode(4,TreeNode(5,None,None),TreeNode(1,None,None)))) , 22))
      
        
        
        
        
        
        
        