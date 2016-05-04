INF = 10**9 + 7
# def substrings(a):
# 	# subs = []
# 	for i in xrange(1,len(a)+1):
# 		for j in xrange(len(a)-i+1):
# 			# subs.append(a[j:j+i])
# 			yield a[j:j+i]
# 	# return subs
# # print substrings(raw_input())

# def bf(n):
# 	a = str(n)
# 	ans = 0
# 	for s in substrings(a):
# 		ans += int(s)
# 	return ans
# print bf(input())%INF

def solve(n):
	a = str(n)
	ans = 0
	for i in xrange(1,len(a)+1):
		ans += i*int(a[i-1]*(len(a)-i+1))
		ans %= INF
	return ans%INF

print solve(raw_input())