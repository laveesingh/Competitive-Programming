

for _ in xrange(input()):
    n = input()
    a = map(int, raw_input().split())
    b = []
    posn = 0
    poss = 0
    for s in a:
        if s >= 0:
            poss += s
            posn += 1
        else:
            b.append(s)
    b.sort(reverse=True)
    negsum = 0
    for s in b:
        if (poss*posn +s) <= (poss+s)*(posn+1):
            poss += s
            posn += 1
            negsum += s
        else:
            break
    negsum = sum(b) - negsum
    print poss*posn + negsum
