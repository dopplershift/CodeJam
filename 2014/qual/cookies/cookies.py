def cookie_time(fh):
    time = 0.
    rate = 2.0
    farm_cost, farm_rate, goal = map(float, fh.readline().split())
    while(goal > (goal * rate/(rate + farm_rate) + farm_cost)):
        time += farm_cost / rate
        rate += farm_rate
    return time + goal / rate

def solve_cookies(filename):
    infile = open(filename, 'r')
    for case in range(int(infile.readline())):
        res = cookie_time(infile)
        print('Case #{0}: {1}'.format(case + 1, res))

if __name__ == '__main__':
    import sys
    solve_cookies(sys.argv[1])
