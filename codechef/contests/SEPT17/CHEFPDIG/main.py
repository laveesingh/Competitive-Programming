from collections import Counter

def solve(astring):
    acounter = Counter(astring)
    ans = []
    for i in xrange(65, 91):
        f = str(i)[0]
        s = str(i)[1]
        if f == s:
            if acounter[f] >= 2:
                ans.append(chr(i))
        else:
            if acounter[f] > 0 and acounter[s] > 0:
                ans.append(chr(i))
    return ''.join(ans)

for _ in xrange(input()):
    astring = raw_input()
    print solve(astring)
