from typing import List
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
      
      R = len(board)
      
      C = len(board[0])
        
      moves = [(1,0) , (-1,0) , (0,1) , (0,-1)]
      
      idx = 0
      
      def is_inGrid(i , j):
        
        return  0 <= i < R and 0 <= j < C   
      
      
      def dfs(i , j):
        
        nonlocal idx
        
        print(i , j, idx)
        if idx >= len(word) or (len(word) == 1 and board[i][j] == word):
          
          return True
        
        if board[i][j] != word[idx] or visited[i][j]:
         
          return False
        
        # record visited
          
        visited[i][j] = True
        
        idx += 1
        # handle changes
        
        for dr , dc in moves:
          
          if is_inGrid(i + dr , j + dc):
            
            if dfs(i + dr , j + dc):
              
              return True
        idx -= 1
              
        return False

      letter_idx = 0
      
      for i in range(R):
        
        for j in range(C):
          
          if board[i][j] == word[letter_idx]:
            
            print(i,j)
            
            visited = [[False]*C for _ in range(R)]
            
            idx = 0
            
            if dfs(i,j):
              
              return True
              
            
            
      return False
        
      #respond and change
        
        
              
s = Solution()
print(s.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],"SEE"))
            
            
    