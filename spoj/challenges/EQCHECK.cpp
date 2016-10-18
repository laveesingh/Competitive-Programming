#include <bits/stdc++.h>
using namespace std;
int t,x,y,c,i;string T;
main(){scanf("%d",&t);while(t--){scanf("%dx+%dy=%d",&x,&y,&c);printf((c%__gcd(x,y)?"no\n":"yes\n"));}}
