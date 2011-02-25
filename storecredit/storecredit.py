import sys
import numpy as np

fname = sys.argv[1]

infile = open(fname, 'r')

N = int(infile.readline())

for case in xrange(N):
    credit = int(infile.readline())
    numItems = int(infile.readline())
    items = np.array([int(i) for i in infile.readline().split()])
    pairs = items + items[:, np.newaxis]
    pairs[range(numItems), range(numItems)] = -1
    pickedItems = list((pairs == credit).nonzero()[0] + 1)
    pickedItems.sort()
    print 'Case #%d:' % (case + 1), ' '.join('%d'%i for i in pickedItems)

