from bisect import bisect_right

def deceit_war(ken, naomi):
    wins = 0

    for n in naomi:
        # Naomi wins, Ken throws away smallest
        if n > ken[0]:
            k = ken.pop(0)
            wins += 1
        # Naomi makes Ken win using biggest
        else:
            k = ken.pop()

        #print(n,k,wins)
    return wins

def war(ken, naomi):
    wins = 0
    for n in reversed(naomi):
        # Naomi wins always, Ken throws away smallest
        if n > ken[-1]:
            k = ken.pop(0)
            wins += 1
        # Ken wins usins smallest possible
        else:
            k = ken.pop(bisect_right(ken, n))
        #print(n,k,wins)
    return wins

def solve_war(filename):
    infile = open(filename, 'r')
    for case in range(int(infile.readline())):
        num = int(infile.readline())
        naomi = sorted(map(float, infile.readline().split()))
        ken = sorted(map(float, infile.readline().split()))
        print('Case #{0}: {1} {2}'.format(case + 1, deceit_war(ken.copy(), naomi.copy()),
            war(ken, naomi)))

if __name__ == '__main__':
    import sys
    solve_war(sys.argv[1])
