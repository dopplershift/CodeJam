import sys
from itertools import izip

fname = sys.argv[1]
infile = open(fname, 'r')
N = int(infile.readline())

keymap = {' ':'0', '\n':'\n'}
key = 2
mult = 1
for l in range(ord('a'), ord('a') + 26):
    keymap[chr(l)] = str(key) * mult
    mult += 1
    if mult > 3 and (key not in (7,9) or mult > 4):
        mult = 1
        key += 1

for case in xrange(N):
    tr_chars = [keymap[c] for c in infile.readline()]
    tr_msg = []
    for p,n in izip(tr_chars[:-1], tr_chars[1:]):
        tr_msg.append(p)
        if p[0] == n[0]:
            tr_msg.append(' ')
    tr_msg.append(tr_chars[-1])
    print 'Case #%d:' % (case + 1), ''.join(tr_msg),

