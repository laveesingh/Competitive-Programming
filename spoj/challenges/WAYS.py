u=input
D=[[1]*14for i in r(14)]
i=1
exec("j=1;exec('D[i][j]=D[i-1][j]+D[i][j-1];j+=1;'*14);"*14)
exec("x=u();print D[x][x];"*u())
