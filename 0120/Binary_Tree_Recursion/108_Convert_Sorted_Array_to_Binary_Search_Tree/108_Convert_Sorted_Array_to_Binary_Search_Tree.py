from typing import Optional , List
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def __init__(self):
      self.up_right = True 
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
      nums.sort()
      if len(nums) == 1:
        center = TreeNode(nums[0],None,None)
      
      elif len(nums) % 2 == 0:
        if self.up_right:
          center = TreeNode(nums[len(nums)//2],None,None)
          center.left = self.sortedArrayToBST(nums[:len(nums)//2])
          if len(nums)//2 + 1 < len(nums) and nums[len(nums)//2 + 1:]:
            center.right = self.sortedArrayToBST(nums[len(nums)//2 + 1:])
          else:
            center.right = None
        elif not self.up_right:
          center = TreeNode(nums[len(nums)//2 - 1],None,None)
          if len(nums)//2 + 1 < len(nums) and nums[:len(nums)//2 - 1]:
            center.left = self.sortedArrayToBST(nums[:len(nums)//2 - 1])
          else:
            center.left = None
          center.right = self.sortedArrayToBST(nums[len(nums)//2:])
      elif len(nums) % 2 == 1:
        center = TreeNode(nums[len(nums)//2],None,None)
        self.up_right = True
        center.left = self.sortedArrayToBST(nums[:len(nums)//2])
        self.up_right = False
        center.right = self.sortedArrayToBST(nums[len(nums)//2+1:])
        
      return center
def TreeNode_format(node):
 
    if node == None:
      return None
      
    left = TreeNode_format(node.left) if node.left else None
    right = TreeNode_format(node.right) if node.right else None
    
    return f"TreeNode({node.val},{left},{right})"
    
s = Solution()
print(TreeNode_format(s.sortedArrayToBST([-10,-3,0,5,9])))
