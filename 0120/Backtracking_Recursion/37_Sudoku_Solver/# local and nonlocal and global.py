# local and nonlocal and global

x  = 1
board = [1,2,3]

#1: modify global valuable (object)
def func_a():
    board[0] = 2 #[1,2,3] (modify object [1,2,3])
def func_b():
    
    x += 2 # error 
    # x(valuable) -> 1(object)
    # x(valuable) -> 3(object)


#2: modify global valuable(global)
def func_c():
    global x
    x += 1
#3: new valuable
def func_d():
    
    x = 2 # x is new valuable and it will die after function
    # x = 1




func_a()
print(board)
print(x)