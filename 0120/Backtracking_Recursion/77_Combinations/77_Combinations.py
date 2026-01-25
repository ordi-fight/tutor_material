from typing import List
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:

        nums = list(range(1,n+1))
        result_list = []
        def recur(lst , idx):
            # base case
            if len(lst) == k:
                result_list.append(lst)
                return
            elif idx >= n:
              return
            # handle choices
            recur(lst, idx + 1)  
            recur(lst + [nums[idx]], idx + 1)
            # [] , 1
            return
        recur([],0)
        return result_list
s = Solution()
print(s.combine(4,2))