import sys

fname = sys.argv[1]
infile = open(fname, 'r')
N = int(infile.readline())

for case in xrange(N):
    words = infile.readline().split()

    print 'Case #%d:' % (case + 1), ' '.join(words[::-1])

