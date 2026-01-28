# Definition for a binary tree node.
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        
        def rec(start, end):
            if start > end:
                return None
            length = end - start + 1
            pivot = start + length // 2

            return TreeNode(nums[pivot], rec(start, pivot - 1), rec(pivot + 1, end))

        return rec(0, len(nums) - 1)
