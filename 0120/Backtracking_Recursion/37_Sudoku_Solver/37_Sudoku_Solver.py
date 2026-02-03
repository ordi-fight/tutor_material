from typing import List
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        

        def isvalid(i,j,val):
         
          if board[i][j] != '.':
              return False
          area_i = i//3
          area_j = j//3

          for x in range(9):
            
              for y in range(9):

                  # row

                  if board[i][y] != '.' and int(board[i][y]) == val:

                      return False
                  
                  #column
                  if board[x][j] != '.' and int(board[x][j]) == val:

                      return False
                  
                  #block

                  area_x = x//3
                  area_y = y//3

                  if area_x == area_i and area_y == area_j and board[x][y] != '.' and int(board[x][y]) == val:

                      return False
          return True
        def recur(x,y):
          nonlocal board
          # base case
          if y >= 9:
            return True
          # val
          if board[x][y] == '.':
            for val in range(1,10):
              if isvalid(x,y,val):
                board[x][y] = str(val)
                if x + 1 >= 9: #8
                  
                  if not recur(0,y + 1):
                    board[x][y] = '.'
                    continue
                  else:
                    return True  
                  
        
                else:
                  if not recur(x+1,y):
                    board[x][y] = '.'
                    continue
                  else:
                    return True
            return False
            
          # handle choices
         
          if x + 1 >= 9: #8
          
            return recur(0,y + 1)
        
          else:
            return recur(x+1,y)

  
        recur(0,0)
  
  
board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]

solveSudoku(board)   

print(board)
 
  
  
    
    
    