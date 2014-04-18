def get_grid(rows, cols, mines):
    true_empty = rows*cols - mines
    ret = [['*'] * cols for r in range(rows)]
    empty = 1
    ret[0][0] = 'c'

    if empty < true_empty:
        if rows > 1:
            ret[1][0] = '.'
            empty += 1

        if cols > 1:
            ret[0][1] = '.'
            empty += 1

        if cols > 1 and rows > 1:
            ret[1][1] = '.'
            empty += 1

    for s in range(2, max(rows, cols)):
        if s < cols:
            for r in range(min(s + 1, rows)):
                if ret[r][s] == '*' and empty < true_empty:
                    ret[r][s] = '.'
                    empty += 1

        if s < rows:
            for c in range(min(s + 1, cols)):
                if ret[s][c] == '*' and empty < true_empty:
                    ret[s][c] = '.'
                    empty += 1
        if empty == true_empty:
            break

    if empty == true_empty:
        return '\n'.join(''.join(c[0] for c in r) for r in ret)
    else:
        return 'Impossible'

def solve_mines(filename):
    infile = open(filename, 'r')
    for case in range(int(infile.readline())):
        rows,cols,mines = map(int, infile.readline().split())
        print('Case #{0}:'.format(case + 1))
        print get_grid(rows, cols, mines)

if __name__ == '__main__':
    import sys
    solve_mines(sys.argv[1])
