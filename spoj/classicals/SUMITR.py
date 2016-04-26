# w=xrange
# a=[[0for i in w(21)]for j in w(21)]
# u=input
# for _ in w(u()):
# 	n=u()
# 	for i in w(1,n+1):
# 		a[i][1:i+1]=map(int,raw_input().split());j=i;a[i][j]=0
# 		for j in w(1,i+1):a[i][j]+=max(a[i-1][j],a[i-1][j-1])
# 	r=a[n][1]
# 	for i in w(2,n+1):r=max(r,a[n][i])
# 	print r

# w=xrange
# u=input
# exec("n=u();i=1;exec('a[i][1:i+1]=map(int,raw_input().split());j=i;a[i][j]=0;i+=1;for j in w(1,i+1):a[i][j]+=max(a[i-1][j],a[i-1][j-1]);'*n);r=a[n][1];for i in w(2,n+1):r=max(r,a[n][i]);print r;"*u())
x=xrange
u=input
for _ in x(u()):
	a=[[0for i in x(111)]for j in x(111)]
	n=u()
	for i in x(1,n+1):a[i][1:i+1]=map(int,raw_input().split())
	for i in x(2,n+1):
		for j in x(1,i+1):a[i][j]+=max(a[i-1][j],a[i-1][j-1])
	print max([s for s in a[n]])


# There is something wrong with the optimized code below, while the mirror given above is working fine.
# x=xrange
# u=input
# exec("a=[[0for i in x(111)]for j in x(111)];n=u();i=1;exec('a[i][1:i+1]=map(int,raw_input().split());i+=1;'*n);i=2;exec('''for j in xrange(1,i+1):a[i][j]+=max(a[i-1][j],a[i-1][j-1]);i+=1;\n'''*(n-1));print max([s for s in a[n]]);"*u())


# j=1;exec('a[i][j]+=max(a[i-1][j],a[i-1][j-1]);j+=1;'*i)
# i=2;exec("for j in xrange(1,i+1):a[i][j]+=max(a[i-1][j],a[i-1][j-1]);i+=1;\n"*(n-1))