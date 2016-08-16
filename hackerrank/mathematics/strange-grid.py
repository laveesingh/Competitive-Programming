'''input
6 3
'''

r, c = map(int, raw_input().split())
print 10*((r-1)/2) + 2*(c-1)+((r-1)%2)
