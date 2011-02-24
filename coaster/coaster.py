import sys
from collections import deque

fname = sys.argv[1]
infile = open(fname, 'r')

N = int(infile.readline())
for case in xrange(N):
    runs, size, num_groups = (int(k) for k in infile.readline().split())
    groups = deque(int(k) for k in infile.readline().split())
    total = 0
    for i in xrange(runs):
        car = []
        car_tot = 0
        while groups and (car_tot + groups[0]) <= size:
            next = groups.popleft()
            car.append(next)
            car_tot += next
        groups.extend(car)
        total += car_tot
    print 'Case #%d: %d' % (case + 1, total)
