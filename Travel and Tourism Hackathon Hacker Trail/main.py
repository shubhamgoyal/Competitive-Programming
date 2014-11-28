import sys
# rc = costs of painting red, bc of blue and gc of green.
def min_paint(rc, bc, gc):
    n,i = len(rc),1
    r,b,g = [0]*n,[0]*n,[0]*n
    r[0],b[0],g[0] = rc[0],bc[0],gc[0]
    while i < n:
        r[i] = rc[i] + min(b[i-1], g[i-1])
        b[i] = bc[i] + min(r[i-1], g[i-1])
        g[i] = gc[i] + min(b[i-1], r[i-1])
        i += 1
    return min(r[n-1],b[n-1],g[n-1])

def main():
    r = []
    b = []
    g = []
    count = 0
    n = -1
    for line in sys.stdin:
        if count == 0:
            count = count + 1
            n = int(line)
            continue
        i, j, k = (int(s) for s in line.split())
        r.append(i)
        b.append(j)
        g.append(k)
        count = count + 1
        if count == (n + 1):
            break
    # print r
    # print b
    # print g
    print min_paint(r, b, g)

if __name__ == "__main__":
    main()