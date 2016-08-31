'''input
4 1
3 10 2 9
7
'''

import os, sys, collections, itertools, fractions, math, random

ai = lambda : map(int, raw_input().split())
ii = lambda : int(raw_input())

n, k = ai()
a = ai()
pay = ii()
ans = sum(a)-a[k]
ans /= 2
x = pay-ans
print x if x else "Bon Appetit"
