def read_cases(fname):
    'Read in test case list'
    fobj = open(fname)
    num_cases = int(fobj.readline())
    for n in xrange(num_cases):
        yield make_case(fobj.readline())

def make_case(s):
    'Make a test case from a string'
    return s.split()

NORTH = 1
SOUTH = 2
WEST = 4
EAST = 8

dir_to_comp = {(0,1):NORTH, (1,0):EAST, (0,-1):SOUTH, (-1,0):WEST}

def leftof(direction):
    xdir, ydir = direction
    return -ydir,xdir

def rightof(direction):
    xdir, ydir = direction
    return ydir,-xdir

def solve(forward, backward):
    'Reconstruct a maze from the paths take forwards and backwards'
    grid = dict()
    loc = 0,0
    grid[loc] = 1
    direction = 0,-1
    for step in forward[1:-1]:
        if step == 'W':
            grid[loc] = grid.setdefault(loc, 0) | dir_to_comp[direction]
            loc = loc[0] + direction[0], loc[1] + direction[1]
        elif step == 'L':
            direction = leftof(direction)
        elif step == 'R':
            direction = rightof(direction)

    grid[loc] = grid.setdefault(loc, 0) | dir_to_comp[direction]
    direction = -direction[0], -direction[1]
    for step in backward[1:-1]:
        if step == 'W':
            grid[loc] = grid.setdefault(loc, 0) | dir_to_comp[direction]
            loc = loc[0] + direction[0], loc[1] + direction[1]
        elif step == 'L':
            direction = leftof(direction)
        elif step == 'R':
            direction = rightof(direction)

    xmax = max(loc[0] for loc in grid)
    xmin = min(loc[0] for loc in grid)
    ymax = max(loc[1] for loc in grid)
    ymin = min(loc[1] for loc in grid)
    return [[hex(grid.get((c,r), 0))[-1] for c in xrange(xmin, xmax + 1)]
                                 for r in xrange(ymax, ymin - 1, -1)]


if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1:
        fname = sys.argv[1]
    else:
        fname = 'maze-test.in'

    for num,case in enumerate(read_cases(fname)):
        print 'Case #%d:' % (num + 1)
        grid = solve(*case)
        for row in grid:
            print ''.join(row)
