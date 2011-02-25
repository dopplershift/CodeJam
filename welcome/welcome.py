import sys
import numpy as np

fname = sys.argv[1]
infile = open(fname, 'r')
N = int(infile.readline())

s = 'welcome to code jam'

def count_substr(source, s):
    char = s[0]
    if len(s) == 1:
        count = source.count(char)
    else:
        count = 0
        ind = source.find(char)
        while ind >= 0:
            print ind
            count += count_substr(source[ind + 1:], s[1:])
            ind = source.find(char, ind + 1)
    return count

def count_substr(source, s):
    char = s[0]
    if len(s) == 1:
        count = source.count(char)
    else:
        count = 0
        ind = source.find(char)
        while ind >= 0:
            print ind
            count += count_substr(source[ind + 1:], s[1:])
            ind = source.find(char, ind + 1)
    return count

for case in xrange(N):
    line = infile.readline()
    chars = ''.join(c for c in line[line.find(s[0]):line.rfind(s[-1]) + 1] if c in s)
    char_nums = np.array([ord(c) for c in chars])
#    print chars
    char_counts = dict((c, (char_nums==ord(c)).cumsum()) for c in set(s))
#    print char_counts
    print 'Case #%d: %04d' % (case + 1, count_substr_count(char_counts, s))
#    print 'Case #%d: %04d' % (case + 1, count_substr(chars, s))

