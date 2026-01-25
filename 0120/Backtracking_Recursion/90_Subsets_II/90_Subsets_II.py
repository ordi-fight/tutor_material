from typing import List
from collections import Counter
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result_list  = []
      
      
        def judge_duplicate(children_lst, parent_lst):
            for lst in parent_lst:
              if Counter(children_lst) == Counter(lst):
                return False
            return True
        def recur(lst,idx):
        
            # base case  (the last)
            
            if idx == len(nums)   :
                if judge_duplicate(lst,result_list):
                  result_list.append(lst)
                
                return
        
            # handle choices
            
            recur(lst, idx + 1)
            
            recur(lst + [nums[idx]] , idx + 1)
            
            return 
          
        # recur
      
        recur([],0)
      
      
        return  result_list
s = Solution()
print(s.subsetsWithDup([4,4,4,1,4]))