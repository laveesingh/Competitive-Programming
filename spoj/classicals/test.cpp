#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<algorithm>

#define psb push_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define N 1000100
#define sf scanf
#define pf printf

using namespace std;

typedef long long LL;
typedef vector<LL>vll;

LL ar[N] , num[N];

int main()
{
    int t , tc=0;
    //cin >> t;
    sf("%d",&t);

    while(t--)
    {
        LL n, x, arlen=-1, nmlen=-1 , i , maxi=-1 , zar;
        char c;

        //cin >> n;
        sf("%lld",&n);
        //cout << "Case " << ++tc << ":\n";
        pf("Case %d:\n",++tc);
        getchar();

        while(n--)
        {
            //cin >> c;
            sf("%c",&c);

            if(c == 'A')
            {
                //cin >> x;
                sf("%lld",&x);

                nmlen++; //cout << nmlen << " ";

                num[nmlen] = x;

                if(x >= maxi)
                {
                    maxi = x;

                    arlen++;

                    ar[arlen] = maxi;
                }
            }

            else if(c == 'R')
            {
                zar = num[nmlen];

                if(zar == maxi)
                {
                    if(nmlen >= 0)
                    {
                        nmlen--;
                        arlen--;
                        maxi = ar[arlen];
                    }
                }

                else
                {
                    if(nmlen >= 0)
                    {
                        nmlen--;
                    }
                }
            }

            else if(c == 'Q')
            {
                if(nmlen < 0)
                {
                    //cout << "Empty\n";
                    pf("Empty\n");
                }

                else
                {
                    //cout << maxi << "\n";
                    pf("%lld\n",maxi);
                }
            }

            getchar();
        }
    }

    return 0;
}