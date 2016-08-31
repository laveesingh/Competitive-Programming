'''input
5 7
abcba
1
2
3
4
6
7
8
'''

import os, sys, collections, itertools, fractions, math, random

ai = lambda : map(int, raw_input().split())
ii = lambda : int(raw_input())



mod = 10**9 + 7

def evaluate(s):
    n = len(s)
    ans = 0
    for i in xrange(n-1,-1,-1):
        ans += ord(s[n-1-i])*pow(100001, i, mod)
        ans %= mod
    return ans


def allpals(s):
    pals = []
    for c in xrange(len(s)):
    	i = c
    	j = i+1
    	while i >= 0 and j < len(s) and s[i]==s[j]:
    		pals.append(s[i:j+1])
    		i -= 1
    		j += 1
    	i = c-1
    	j = c+1
    	while i >= 0 and j < len(s) and s[i] == s[j]:
    		pals.append(s[i:j+1])
    		i -= 1
    		j += 1
    pals.extend(list(s))
    return sorted(pals)


n, q = ai()
s = raw_input()
pals = allpals(s)
for i in xrange(q):
    x = ii()-1
    if x >= len(pals):
        print -1
    else:
        print evaluate(pals[x])