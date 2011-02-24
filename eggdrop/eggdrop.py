class Memoize:
    def __init__(self, func):
        self.func = func
        self.cache = {}
    def __call__(self, *args):
        if args not in self.cache:
            self.cache[args] = self.func(*args)
        return self.cache[args]

def search(low, high, func, value):
    if func(low) == value: return low
    if func(high) == value: return high
    low += 1
    high -= 1

    guess = (high + low) // 2
    guess_val = func(guess)
    while low <= high and guess_val != value:
        guess = (high + low) // 2
        guess_val = func(guess)
        if guess_val == value:
            break
        elif guess_val > value:
            high = guess - 1
        else:
            low = guess + 1

    return guess

def read_cases(fname):
    'Read in test case list'
    fobj = open(fname)
    num_cases = int(fobj.readline())
    for n in xrange(num_cases):
        yield make_case(fobj.readline())

def make_case(s):
    'Make a test case from a string'
    return map(int, s.split())

@Memoize
def f(drop, brk):
    if drop == 0 or brk == 0:
        return 0
    elif drop == 1:
        return 1
    elif brk == 1:
        return drop
    elif brk == 2:
        return ((drop + 1) * drop) / 2
    elif brk == 3:
        return ((drop * drop + 5) * drop) / 6
    else:
        a = f(drop - 1, brk)
        b = f(drop - 1, brk - 1)
        if a == -1 or b == -1 or a + b + 1 >= 4294967296:
            return -1
        else:
            return a + b + 1

def solve(floors, maxdrop, maxbreak):
    'Solve egg drop problem'

    maxfloors = f(maxdrop, maxbreak)

    mindrop = search(1, maxdrop, lambda d,b=maxbreak: f(d, b), floors)
    minbreak = search(1, maxbreak, lambda b,d=maxdrop: f(d, b), floors)

    return maxfloors, mindrop, minbreak

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1:
        fname = sys.argv[1]
    else:
        fname = 'eggdrop-test.in'

    for num,case in enumerate(read_cases(fname)):
        print 'Case #%d: %d %d %d' % ((num + 1,) + solve(*case))
