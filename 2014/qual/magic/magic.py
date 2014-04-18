def get_row(fh):
    # Get row number 
    row = int(fh.readline())

    # Read grid
    grid = [map(int, fh.readline().split()) for i in range(4)]

    # Return this row
    return set(grid[row - 1])

def solve_magic(filename):
    infile = open(filename, 'r')
    for case in range(int(infile.readline())):
        num = get_row(infile) & get_row(infile)
        if not num:
            res = 'Volunteer cheated!'
        elif len(num) > 1:
            res = 'Bad Magician!'
        else:
            res = next(iter(num))
        print('Case #{0}: {1}'.format(case + 1, res))

if __name__ == '__main__':
    import sys
    solve_magic(sys.argv[1])
