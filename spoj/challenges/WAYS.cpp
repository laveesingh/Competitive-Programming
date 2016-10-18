f(int x){return x<2?2:f(x-1)*(4*x-2)/x;}S="%d\n";main(t,n){for(scanf(l,&t);t--;scanf(l,&n),printf(l,f(n)));}
