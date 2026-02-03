from typing import List
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
      
      res = 0
      
      
      table = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]
      
      
      def dfs(x,y):
        nonlocal res
        if grid[x][y] == '1':
          
          table[x][y] = True
          
          if x + 1 < len(grid) and table[x+1][y] == False and grid[x + 1][y] == '1':
              dfs(x + 1,y)
          if x - 1 >= 0 and table[x-1][y] == False and grid[x - 1][y] == '1':
              dfs(x - 1,y)
          
          if y + 1 < len(grid[0]) and table[x][y+1] == False and grid[x][y + 1] == '1':
              dfs(x , y+1)
          if y - 1 >= 0 and table[x][y-1] == False and  grid[x][y - 1] == '1':
              dfs(x , y - 1)
         
          return
           
      for x in range(len(grid)):
        for y in range(len(grid[0])):
          
          if table[x][y] == False and grid[x][y] == '1':
            
            dfs(x,y)
            
            res += 1
            
      return res