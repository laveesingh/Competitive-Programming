#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI >    VVI;
typedef long long int   LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fll(i,n) for(LL i=0;i<n;i++)

//#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1& arg1, Args&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
int main()
{
    fast_io;//this makes cin cout faster
    int t;
    cin >> t;
    while (t--){
        
        char a[1004];
        cin>>a;
        char c1[19]={'A','b','d','H','I','M','O','o','T','U','V','W','X','Y','v','w','x','p','q'};
        char c2[19]={'A','b','d','H','I','M','O','o','T','U','V','W','X','Y','v','w','x','p','q'};
        int x=0;
        int ind1=-10;
        int len=strlen(a);
        trace(len);
        for(int i=0;i<=strlen(a)/2;i++)
        {
            ind1=-10;
            for(int j=0;j<19;j++)
            {
                if(a[i]==c1[j])
                {
                    ind1=j;
                    break;
                }
            }
            if(ind1==-10)
            {
                printf("NIE\n");
                x=1;
                break;
            }
            else
            {
                trace(c2[2],a[t]);
                if(ind1==2)
                {
                    if(a[strlen(a)-i-1]!=c2[1]) 
                    {
                        printf("NIE\n");
                        x=1;
                        break;
                    }
                }
                else if(ind1==1)
                {
                    if(a[len-i-1]!=c2[2])
                    {
                        printf("NIE\n");
                        x=1;
                        break;
                    }
                }
                else if(ind1==18)
                {
                    if(a[strlen(a)-i-1]!=c2[17]) 
                    {
                        printf("NIE\n");
                        x=1;
                        break;
                    }
                }
                else if(ind1==17)
                {
                    if(a[len-i-1]!=c2[18])
                    {
                        printf("NIE\n");
                        x=1;
                        break;
                    }
                }

                else if(a[strlen(a)-i-1]!=c2[ind1])
                {
                    printf("NIE\n");
                    x=1;
                    break;
                }
            }
        }
        if(!x)
            printf("TAK\n");
    }

    return 0;
}