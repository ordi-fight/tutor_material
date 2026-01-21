# try to use recur_path to accumulate node.val

from typing import Optional , List
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:

        result_list = []
        path = ""
        def is_leaf(node):

            if isinstance(node, TreeNode) and node.left == None and node.right == None:

                return True
            return False

        def recur(node,path):
            # base case
            if node == None:

                return result_list

            if is_leaf(node) :

                path = path + f"{node.val}"

                result_list.append(path)

                return
            
            # choice handle

            path = path + f"{node.val}->"

            recur(node.left,path)
            recur(node.right,path)

            return
        
        recur(root,path)

        return result_list
            


        




        