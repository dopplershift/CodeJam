import sys
#import numpy # http://numpy.scipy.org

def calc_cost(x, y):
    diff = abs(x - y)
    if M > 0:
        return min([D, max(0, diff - M), I * (diff // M)])
    else:
        return min([D, max(0, diff - M)])

fname = sys.argv[1]
infile = open(fname, 'r')

N = int(infile.readline())
for case in xrange(N):
    D,I,M,n = (int(k) for k in infile.readline().split())
    data = [int(k) for k in infile.readline().split()]
    if n == 1:
        cost = 0
    elif n == 2:
        x,y = data
        cost = calc_cost(x, y)
    elif n == 3:
        x,y,z = data
        cost1 = calc_cost(x, y)
        cost2 = calc_cost(y, z)
        cost3 = calc_cost(x, z)
        cost = min([cost1 + cost2, D + cost3])
        if abs(x - z) <= 2 * M:
            cost4 = max(0, min(abs(x - y) - M, abs(z - y) - M))
            cost = min(cost, cost4)

    print 'Case #%d: %s' % (case + 1, cost),
    print '(D: %d I: %d M: %d %s)' % (D,I,M,str(data))
