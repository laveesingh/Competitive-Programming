p,f,u=5**.5,lambda n:((1+p)**n-(1-p)**n)/(2**n*p),input
exec"n=u();print int(f(n+11)-f(n+1)+f(n+6)%10);"*u()
