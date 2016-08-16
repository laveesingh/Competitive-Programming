'''input
5
0 1 2 3 4
'''

mod = 10**9+7

n = input()
a = map(int, raw_input().split())

ans = 1

for i in xrange(1,n):
	if a[i] == -1:
		poss = range(i+1)
		nposs = 0
		for s in poss:
			flag = True
			for j in xrange(2*i,n,i):
				if a[j] == -1 or a[j]%i == poss%i:
					None
				else:
					flag = False
					break
			if flag:
				nposs += 1
		ans = (ans*nposs)%mod
	else:
		for j in xrange(2*i,n,i):
			if a[j] == -1 or a[j]%i == a[i]%i:
				None
			else:
				ans = 0
	
print ans