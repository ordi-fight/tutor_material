# Definition for a binary tree node.
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution1:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if root == None:
            return []
        
        if root.left == None and root.right == None:
            return [str(root.val)]
        
        result = []

        if root.left:
            leftList = self.binaryTreePaths(root.left)
            for path in leftList:
                result.append(f'{root.val}->{path}')

        if root.right:
            rightList = self.binaryTreePaths(root.right)
            for path in rightList:
                result.append(f'{root.val}->{path}')

        return result

class Solution2:
    def __init__(self):
        self.result = []

    def recursion(self, root: Optional[TreeNode], curPath: str):
        curPath += str(root.val) if curPath == "" else f'->{root.val}'
        if root.left == None and root.right == None:
            self.result.append(curPath)
            return
        
        if root.left:
            self.recursion(root.left, curPath)
        if root.right:
            self.recursion(root.right, curPath)

        return

    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if root:
            self.recursion(root, "")
        return self.result