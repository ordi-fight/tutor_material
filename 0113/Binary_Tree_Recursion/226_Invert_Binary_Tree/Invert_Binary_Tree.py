from typing import Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        if root == None:
            return None
        root.left, root.right = root.right, root.left
        root.left = self.invertTree(root.left)
        root.right = self.invertTree(root.right)
        return root


        # if isinstance(root,TreeNode):
        #     if root.left != None or root.right != None:

        #         root.left , root.right = self.invertTree(root.right) , self.invertTree(root.left)

        #         return root
                
        #     elif root.left == None and root.right == None:

        #         return root 
        # elif root == None:

        #     return None  
        
