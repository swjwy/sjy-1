#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
pair<LL,LL>exgcd(LL n,LL m);
LL quick(LL n,LL m,LL mod);
int main(void)
{
        LL m,a,b,c;
        LL x,y,z;
        int T;
        scanf("%d",&T);
        while(T--)
        {scanf("%lld %lld %lld %lld",&m,&a,&b,&c);
        if(m&(m-1))
        {
            pair<LL,LL>ask = exgcd(c,a*b);
            ask.second = -ask.second;
            while(ask.first<0||ask.second<0)
            {
                ask.first+=a*b;
                ask.second+=c;
            }
            x = quick((LL)2,ask.second*b,m);
            y = quick((LL)2,ask.second*a,m);
            z = quick((LL)2,ask.first,m);
        }
        else
        {       //printf("1\n");
                if(a > 1)
                {
                        x = m/2;
                        y = 1;
                        z = 1;
                }
                else if(b>1)
                {
                        x = 1;
                        y = m/2;
                        z = 1;
                }
                else if(c > 1)
                {
                        x = m/2;
                        y = m/2;
                        z = m/2;
                }
                else
                {
                        x = 1;
                        y = 1;
                        z = 2;
                }
        }
        printf("%lld %lld %lld\n",x,y,z);}
        return 0;
}
pair<LL,LL>exgcd(LL n,LL m)
{
        if(m==0)
                return make_pair(1,0);
        else
        {
                pair<LL,LL>ak = exgcd(m,n%m);
                return make_pair(ak.second,ak.first-(n/m)*ak.second);
        }
}
LL quick(LL n,LL m,LL mod)
{
    LL ask = 1;
    while(m)
    {
        if(m&1)
            ask = ask*n%mod;
        n = n*n%mod;
        m/=2;
    }
    return ask;
}
