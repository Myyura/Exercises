# Su Doku
# Myyura

# Su Doku (Japanese meaning number place) is the name given to a popular puzzle 
# concept. Its origin is unclear, but credit must be attributed to Leonhard Euler 
# who invented a similar, and much more difficult, puzzle idea called Latin 
# Squares. The objective of Su Doku puzzles, however, is to replace the blanks 
# (or zeros) in a 9 by 9 grid in such that each row, column, and 3 by 3 box 
# contains each of the digits 1 to 9. Below is an example of a typical starting 
# puzzle grid and its solution grid.

# A well constructed Su Doku puzzle has a unique solution and can be solved by 
# logic, although it may be necessary to employ "guess and test" methods in order 
# to eliminate options (there is much contested opinion over this). The complexity 
# of the search determines the difficulty of the puzzle; the example above is 
# considered easy because it can be solved by straight forward direct deduction.

# The 6K text file, sudoku.txt (right click and 'Save Link/Target As...'), contains 
# fifty different Su Doku puzzles ranging in difficulty, but all with unique 
# solutions (the first puzzle in the file is the example above).

# By solving all fifty puzzles find the sum of the 3-digit numbers found in the top 
# left corner of each solution grid; for example, 483 is the 3-digit number found 
# in the top left corner of the solution grid above.

def solve_sudoku(board, square, row, col, i, j):
    square_index = (i // 3) * 3 + j // 3
    for k in range(1, 10):
        if row[i][k] == 1 or col[j][k] == 1 or square[square_index][k] == 1:
            continue
        
        board[i][j] = k
        square[square_index][k] += 1
        row[i][k] += 1
        col[j][k] += 1

        next_i = i
        next_j = j
        while board[next_i][next_j] != 0:
            next_j += 1
            if next_j == 9:
                next_j = 0
                next_i += 1
            if next_i == 9:
                return True
        
        if solve_sudoku(board, square, row, col, next_i, next_j):
            return True
        
        board[i][j] = 0
        square[square_index][k] -= 1
        row[i][k] -= 1
        col[j][k] -= 1

    return False

def read_a_sudoku(input_file):
    input_file.readline()
    board = [[0 for _ in range(9)] for _ in range(9)]
    for i in range(9):
        line = input_file.readline()
        for j in range(9):
            board[i][j] = int(line[j])
    return board

def sudoku():
    input_file = open("../data/p96_sudoku.txt", "r")

    result = 0
    for _ in range(50):
        board = read_a_sudoku(input_file)
        square = [[0 for _ in range(10)] for _ in range(9)]
        row = [[0 for _ in range(10)] for _ in range(9)]
        col = [[0 for _ in range(10)] for _ in range(9)]

        first_i = -1
        first_j = -1
        for i in range(9):
            for j in range(9):
                square_index = square_index = (i // 3) * 3 + j // 3
                if board[i][j] != 0:
                    square[square_index][board[i][j]] += 1
                    row[i][board[i][j]] += 1
                    col[j][board[i][j]] += 1
                else:
                    if first_i == -1:
                        first_i = i
                    if first_j == -1:
                        first_j = j
        
        solve_sudoku(board,square, row, col, first_i, first_j)
        result += board[0][0] * 100 + board[0][1] * 10 + board[0][2]

    input_file.close()
    return result

print(sudoku())