gcd(m,n){return n==0?m:gcd(n,m%n);}
main(a,b,c,t,g){scanf("%d",&t);while(t--){scanf("%dx+%dy=%d",&a,&b,&c);printf((c%gcd(a,b)?"no\n":"yes\n");}}
