u=input;F=lambda n,m:1 if not(n and m)else F(n,m-1)+F(n-1,m)
exec("x=u();print F(x,x);"*u())
