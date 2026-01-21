from typing import List
class Solution:
       def letterCombinations(self, digits: str) -> List[str]:
      
            match_dict = {2: ["a","b","c"] ,3: ["d","e","f"],
            4:["g","h","i"] , 5:["j","k","l"],
            6:["m","n","o"], 7:["p","q","r","s"] , 8:["t","u","v"]
            , 9:["w","x","y","z"] }
            
            result_list = []
                
            posi = ""
            
            def recur(posi : str,index : int):
                
                print(posi)
                
                # base case
                if digits == "":
                    
                    return 

                if len(posi) >= len(digits) :
                    
                    result_list.append(posi)
                    
                    return
                # handle choices
                
                lst = match_dict[int(digits[index])]
                
                for char in lst:
                    
                    
                    recur(posi + char ,index + 1)
                    
                    
                    
                return
            recur(posi,0)
            
            return result_list
                