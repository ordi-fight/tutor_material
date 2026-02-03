from typing import List
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # table 
        
        row = [[False]*10 for _  in range(9)]
        col = [[False]*10 for _  in range(9)]
        area = [[False]*10 for _  in range(9)]
        
        def first_run():
          
          for i in range(9):
            for j in range(9):
              
              if board[i][j] != '.':
                val = int(board[i][j])
                row[i][val] = True
                col[j][val] = True
                area[(i //3) * 3 + j//3][val] = True
        first_run()
        
        def recur(idx):
          
          if idx >= 9*9:
            return True
          
          currow = idx // 9
          curcol = idx % 9
          curarea = (currow // 3) * 3 + curcol//3
          
          if board[currow][curcol] == '.':
            for val in range(1,10):
              
              if row[currow][val] == False and col[curcol][val] == False and area[curarea][val] == False:
                
                board[currow][curcol] = str(val)
                row[currow][val] = True
                col[curcol][val] = True
                area[curarea][val] = True
                if not recur(idx + 1):
                  
                  board[currow][curcol] = '.'
                  row[currow][val] = False
                  col[curcol][val] = False
                  area[curarea][val] = False
                else:
                  
                  return True
            return False
          return recur(idx + 1)
          
        recur(0)