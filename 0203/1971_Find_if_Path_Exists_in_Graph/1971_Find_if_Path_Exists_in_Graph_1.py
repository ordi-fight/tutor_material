from typing import List
class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
      
      R = len(edges)
      
      table = [False for _ in range(R)] 
      
      def dfs(source):
        if  source == destination:
          
          return True
        for i in range(len(edges)):
          
          if table[i] == True:
            
            continue
          
          if  edges[i][0] == source:
            
            table[i] = True
            if edges[i][1] == destination:
              
              return True
            if dfs(edges[i][1]):
              return True
            continue
          
          if  edges[i][1] == source:
            
            table[i] = True
            if edges[i][0] == destination:
              
              return True
            if dfs(edges[i][0]):
              return True
            continue
            
        return False
      return dfs(source)
          
          
s  = Solution()
print( s.validPath( 10, [[4,3],[1,4],[4,8],[1,7],[6,4],[4,2],[7,4],[4,0],[0,9],[5,4]], 5,  9))
            
            
            
          
          