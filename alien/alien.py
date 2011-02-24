def read_cases(fname):
    'Read in test case list'
    fobj = open(fname)
    num_cases = int(fobj.readline())
    for n in xrange(num_cases):
        yield make_case(fobj.readline())

def make_case(s):
    'Make a test case from a string'
    return s.split()

def translate(number, src, dest):
    'Translate a number from one set of digits to another'
    # Convert orginal number to base 10
    src_base = len(src)
    base10 = sum(src.index(dig) * src_base**pos for pos,dig in
        enumerate(reversed(number)))

    # Convert base 10 number to destination
    dest_num = []
    dest_base = len(dest)
    while base10 != 0:
        dig = base10 % dest_base
        dest_num.append(dest[dig])
        base10 = (base10 - dig) / dest_base
    return ''.join(reversed(dest_num))

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1:
        fname = sys.argv[1]
    else:
        fname = 'alien-small.in'

    for num,case in enumerate(read_cases(fname)):
        print 'Case #%d: %s' % (num + 1, translate(*case))
