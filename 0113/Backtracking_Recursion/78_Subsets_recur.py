from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
      
      idx = 0
      result_list  = []
      
      
      def recur(lst,idx):
        
        # base case  (the last)
        
        if idx == len(nums)   :
          
          result_list.append(lst)
          
          return
       
        # handle choices
        
        recur(lst, idx + 1)
          
        recur(lst + [nums[idx]] , idx + 1)
          
        return 
      
      
      # recur
      
      recur([],0)
      
      
      return  result_list