

array_set = set()

def solve(array):
    ans = 1
    array_set.add(tuple(array))
    for i in xrange(len(array)):
        barray = list(array)
        if i == len(barray)-2 and barray[i] > 0 and barray[i+1] > 0:
                barray[i] -= 1
                barray[i+1] -= 1
                barray.append(1)
                ans += solve(barray)
        elif i < len(barray)-2 and barray[i] > 0 and barray[i+1] > 0:
            barray[i] -= 1
            barray[i+1] -= 1
            barray[i+2] += 1
            ans += solve(barray)
    return ans

for _ in xrange(input()):
    n = input()
    a = map(int, raw_input().split())
    # print solve(a)
    array_set.clear()
    solve(a)
    print len(array_set)
