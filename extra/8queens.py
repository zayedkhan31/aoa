BOARD_LENGTH = 8

def print_board(board):
    for i in board:
        print "|", "".join(["%2d" % (v) for v in i]), "|"


def check_positions(board, u, v):
    j, k = u - v, u + v
    for i in xrange(v):
        if board[u][i] == 1:
            return False
        if j >= 0 and board[j][i] == 1:
            return False
        if k < len(board) and board[k][i] == 1:
            return False
        j += 1
        k -= 1
    return True


def solve_recursive(board, i):
    if i >= BOARD_LENGTH: 
        return True 

    for j in xrange(BOARD_LENGTH):
        if not check_positions(board, j, i):
            continue
        board[j][i] = 1
        if solve_recursive(board, i + 1) is True:
            return True
        board[j][i] = 0
    return False


def test_board(board):
    for i in xrange(BOARD_LENGTH):
        for j in xrange(BOARD_LENGTH):
            if board[i][j] == 1:
                print check_positions(board, i, j)

if __name__ == '__main__':
    board = [[0 for i in xrange(BOARD_LENGTH)] for j in xrange(BOARD_LENGTH)]
    #print check_positions(board, 1, 1)
    
    print solve_recursive(board, 0)
    print_board(board)
    print test_board(board)
