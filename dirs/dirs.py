import sys

fname = sys.argv[1]
infile = open(fname, 'r')

N = int(infile.readline())
for case in xrange(N):
    done,total = (int(k) for k in infile.readline().split())
    done_dirs = [infile.readline().strip().split('/') for k in range(done)]
    dirs = [infile.readline().strip().split('/') for k in range(total)]

    dir_map = dict()
    for d in dirs:
        leading = ''
        for level,name in enumerate(d[1:]):
            dir_map.setdefault(level, set()).add(name)
    print dir_map
    print done_dirs
    for d in done_dirs:
        for level,name in enumerate(d[1:]):
            if level in dir_map:
                if name in dir_map[level]:
                    dir_map[level].remove(name)
    print dir_map

    to_be_made = sum(len(s) for s in dir_map.values())

    print 'Case #%d: %s' % (case + 1, to_be_made)
