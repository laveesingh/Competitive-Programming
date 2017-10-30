from __future__ import print_function
import sys

I = lambda : map(float, raw_input().split())

def create_line(p1, p2):
    if p1[0] == p2[0]:
        return (10**9, float(p1[0]))
    k = float(p2[1] - p1[1]) / (p2[0] - p1[0])
    m = k
    c = -k * p1[0] + p1[1]
    return (m, c)

def equals(line1, line2):
    return abs(line1[0] - line2[0]) < .000001 and abs(line1[1] - line2[1]) < .000001

n, x0, y0 = I()
pset = set()
for i in xrange(int(n)):
    pset.add(tuple(I()))

cnt = 0
while pset:
    point = pset.pop()
    line = create_line(point, (x0, y0))
    # print('line: %s' % str(line), file=sys.stderr)
    cnt += 1
    rm_set = set()
    for pt in pset:
        if equals(create_line(pt, (x0, y0)), line) or equals(create_line((x0, y0), pt), line):
            rm_set.add(pt)
    for pt in rm_set:
        pset.remove(pt)

print(cnt)
