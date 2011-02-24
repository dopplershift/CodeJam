import sys

def check_winner(board, width, goal, player):
    match = player * goal

    # Rows and columns
    for i in range(width):
        ind = i * width
        if match in board[ind:ind + width]:
            return True
        elif match in board[i::width]:
            return True

    # First foward diagonal
    diag_for = width + 1
    if match in board[::diag_for]:
        return True

    # First backward diagonal
    diag_back = width - 1
    if match in board[::diag_back]:
        return True

    # Other diagonals
    for i in range(1, width - goal + 1):
        if match in board[i::diag_for]:
            return True
        elif match in board[width - i::diag_back]:
            return True
        elif match in board[i*width::diag_for]:
            return True
        elif match in board[(i + 1) * width - 1::diag_back]:
            return True

    return False

fname = sys.argv[1]
infile = open(fname, 'r')

N = int(infile.readline())
for case in xrange(N):
    width,goal = (int(k) for k in infile.readline().split())
    board = [infile.readline() for i in xrange(width)]
    new_rows = []
    for row in board:
        row = row.replace('.','').strip()
        new_rows.append('.'*(width - len(row)) + row)
    board = ''.join(new_rows)
#    for r in new_rows:print r
    red = check_winner(board, width, goal, 'R')
    blue = check_winner(board, width, goal, 'B')

    if red:
        if blue:
            result = 'Both'
        else:
            result = 'Red'
    elif blue:
        result = 'Blue'
    else:
        result = 'Neither'
    print 'Case #%d: %s' % (case + 1, result)
