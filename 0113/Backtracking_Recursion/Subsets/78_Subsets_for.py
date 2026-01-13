from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:


        subsets = [[]]

        temp_list = []

        for e in nums:

            for subset in subsets:

                temp = subset
                
                temp = temp + [e]
                temp_list.append(temp)        
                
            subsets.extend(temp_list)
            temp_list = []

        return subsets