t=int(raw_input())
for _ in xrange(1,t+1):
    n=int(raw_input());
    a=set()
    if n==0:
        print "Case #%d: %s"%(_,"INSOMNIA")
    for i in xrange(1,1000):
        s=set(str(n*i))
        a=a.union(s)
        if(len(a)==10):
            print "Case #%d: %d"%(_,n*i)
            break