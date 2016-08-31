'''input
22
'''

t = input()
cnt = 3
# cnt >= t+2
while cnt <= t+2:
	cnt <<= 1
cnt >>= 1
# print "cnt:",cnt
dist = t-cnt
print cnt-(dist+2)