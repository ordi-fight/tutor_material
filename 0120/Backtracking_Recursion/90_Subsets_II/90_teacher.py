from typing import List

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result = []
        path = []
        nums.sort()

        def rec(idx):
            if idx >= len(nums):
                result.append(path.copy())
                return
            
            path.append(nums[idx])
            rec(idx + 1)
            path.pop()

            nextIdx = idx
            while nextIdx < len(nums) and nums[idx] == nums[nextIdx]:
                nextIdx += 1
            rec(nextIdx)
        rec(0)
        return result

class Solution2:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()
        
        def rec(start, path):
            result.append(path.copy())
            if start >= len(nums):
                return
            
            for i in range(start, len(nums)):
                if i > start and nums[i] == nums[i-1]:
                    continue
                
                path.append(nums[i])
                rec(i + 1, path)
                path.pop()
            return
        
        rec(0, [])
        return result