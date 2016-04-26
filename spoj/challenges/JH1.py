# u=input
# t=u()
# while t>0:
#  t-=1
#  n=u()
#  a=map(int,raw_input().split())
#  p=sum([s for s in a[1::2]if s>0])
#  q=abs(sum([s for s in a[::2]if s<0]))
#  print['Some Mirrors Lie!','Every Girl Lies!'][p>=q]


 # def case(n):
 # 	print n
 # 	a = [random.randint(-19, 19) for i in xrange(n)]
 # 	for s in a:
 # 		print s,
 # 	print
 # 	p = 0
 # 	q = 0
 # 	for i in xrange(len(a)):
 # 		if 
f=input
for x in f()*[0]:
 c,p,q,n=0,0,0,f()
 n=raw_input().split(' ',n)
 for t in n:
  t=long(t)
  if c>0:c,p=0,p+t*(t>0)
  else:c,q=1,q+t*-1*(t<0)
 if p<q:print'Every Girl Lies!'
 else:print'Some Mirrors Lie!'