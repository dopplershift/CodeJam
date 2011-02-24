import sys

fname = sys.argv[1]
infile = open(fname, 'r')

N = int(infile.readline())
for case in xrange(N):
    num_snappers,num_snaps = (int(k) for k in infile.readline().split())
    pow2 = 2**num_snappers
    result = 'ON' if (num_snaps % pow2) == (pow2 - 1) else 'OFF'
    print 'Case #%d: %s' % (case + 1, result)
