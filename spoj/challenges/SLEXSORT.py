def c(x,y):
	for s,t in zip(x,y):
		if s!=t:return -1if a.index(s)<a.index(t)else 0
	return -1if len(x)<len(y)else 0
u=input
w=range
r=raw_input
exec("a=r();d=[];exec('d.append(r());'*u());d.sort(cmp=c);\nfor s in d:print s\nprint;r();"*u())