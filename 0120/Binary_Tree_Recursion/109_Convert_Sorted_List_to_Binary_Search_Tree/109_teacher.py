# Definition for singly-linked list.
from typing import Optional


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
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        nums = []
        cur = head
        while cur:
            nums.append(cur.val)
            cur = cur.next

        def rec(start, end):
            if start > end:
                return None
            length = end - start + 1
            pivot = start + length // 2

            return TreeNode(nums[pivot], rec(start, pivot - 1), rec(pivot + 1, end))

        return rec(0, len(nums) - 1)