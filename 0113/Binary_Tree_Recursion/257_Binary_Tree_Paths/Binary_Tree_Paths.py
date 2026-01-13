from typing import Optional , List
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if root == None:

            return []

        elif isinstance(root,TreeNode):

            if self.is_leaf(root) == True:

                return [f"{root.val}"]
            elif self.is_leaf(root) == False:

                if root.left and root.right:
                    left = self.match(root,self.binaryTreePaths(root.left))
                    right = self.match(root,self.binaryTreePaths(root.right))

                    return left + right
                elif root.left and not root.right:
                    left = self.match(root,self.binaryTreePaths(root.left))
                    return left
                elif not root.left and  root.right:
                    right = self.match(root,self.binaryTreePaths(root.right))
                    return right
        

    def is_leaf(self,root):

        if isinstance(root,TreeNode) :
            if  root.left == None and root.right == None:
                return True
            return False
    def match(self,root,lst):

        return [f"{root.val}->{e}" for e in lst]