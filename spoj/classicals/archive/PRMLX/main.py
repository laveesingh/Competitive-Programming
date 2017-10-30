from math import factorial as f
from collections import Counter
from itertools import permutations as p
import random
import string

def perms(alist):
    acounter = Counter(alist)
    n = len(alist)
    ans = f(n)
    for key in acounter:
        ans /= f(acounter[key])
    return ans

def solve(astring):
    store = list(astring)
    ans = 0
    for i in xrange(len(astring)):
        for s in set(store):
            if s < astring[i]:
                temp = list(store)
                temp.remove(s)
                ans += perms(temp)
        store.remove(astring[i])
    return ans

def brute(astring):
    aset = set()
    for perm in p(astring):
        aset.add(''.join(perm))
    alist = list(aset)
    alist.sort()
    return alist.index(astring)

# while 1:
    # astring = raw_input()
    # if astring.strip() == "#" or not astring.strip():
        # break
    # # ans = "%d" % (solve(astring) + 1)
    # ans = "%d" % (brute(astring) + 1)
    # print ans.rjust(10)

def case():
    n = random.randint(1, 30)
    astring = ''.join(random.choice(string.lowercase) for s in xrange(n))
    return astring
