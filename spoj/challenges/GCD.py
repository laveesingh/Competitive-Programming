import fractions as f
def next_perm(arr):
	i=len(arr)-1
	while i>0 and arr[i-1]>=arr[i]:
		i-=1
	if i==0:return
	j=len(arr)-1
	while arr[j]<=arr[i-1]:
		j -= 1
	arr[i-1],arr[j]=arr[j],arr[i-1]
	arr[i:]=arr[len(arr)-1:i-1:-1]
import os
I=os.read(0,10**9).split("\n")
for s in I:
	s=sorted(s)
#	print 'list:',s
	x=int(''.join(s))
	for i in xrange(20):
#		print "next:",s
		next_perm(s)
		x=f.gcd(x,int(''.join(s)))
	print x

