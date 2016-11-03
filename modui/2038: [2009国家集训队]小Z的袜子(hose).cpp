#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long LL;
int ans[50005];
typedef struct node
{
    LL l;
    LL r;
    int id;
} ss;
ss ask[50005];
int cnt[50005];
bool cmp1(node p,node q)
{
    return p.l < q.l;
}
bool cmp2(node p,node q)
{
    return p.r<q.r;
}
ss answer[50005];
void slove_mo(int n,int m);
LL gcd(LL n, LL m);
int main(void)
{
    int n,m;
    memset(cnt,0,sizeof(cnt));
    scanf("%d %d",&n,&m);
    int i,j;
    for(i = 1; i <=n; i++)
    {
        scanf("%d",&ans[i]);
    }
    for(i = 0; i < m; i++)
    {
        scanf("%lld %lld",&ask[i].l,&ask[i].r);
        ask[i].id = i;
    }
    sort(ask,ask+m,cmp1);
    int ak = sqrt(1.0*n)+1;
    int v = ak;
    int id = 0;
    for(i = 0; i < m; i++)
    {
        if(ask[i].l > v)
        {
            v+=ak;
            sort(ask+id,ask+i,cmp2);
            id = i;
        }
    }
    sort(ask+id,ask+m,cmp2);
    slove_mo(n,m);
    for(i = 0; i < m; i++)
    {
        printf("%lld/%lld\n",answer[i].l,answer[i].r);
    }
    return 0;
}

void slove_mo(int n,int m)
{
    int i,j;
    LL xl = ask[0].l;
    LL xr = ask[0].r;    LL  sum = 0;
    for(i = ask[0].l;i <= ask[0].r;i++)
    {
        sum = sum - cnt[ans[i]]*cnt[ans[i]];
        cnt[ans[i]]++;
        sum = sum + cnt[ans[i]]*cnt[ans[i]];
    }
     LL hi = sum - (ask[0].r-ask[0].l+1);
        LL low = (LL)(ask[0].r-ask[0].l+1)*(LL)(ask[0].r-ask[0].l);
        LL x = gcd(hi,low);
        answer[ask[0].id].l = hi/x;
        answer[ask[0].id].r = low/x;
    for(i = 1; i < m; i++)
    {
            while(xr < ask[i].r)
            {
                xr++;sum-=(LL)cnt[ans[xr]]*(LL)cnt[ans[xr]];
                cnt[ans[xr]]++;
                sum = sum + (LL)cnt[ans[xr]]*(LL)cnt[ans[xr]];
            //if(i == 1)printf("%lld\n",sum);
        }
            while(xr > ask[i].r)
            {
                sum = sum - (LL)cnt[ans[xr]]*(LL)cnt[ans[xr]];
                cnt[ans[xr]]--;
                sum = sum + (LL)cnt[ans[xr]]*(LL)cnt[ans[xr]];
                xr--;
            }
            while(xl < ask[i].l)
            {
                sum = sum - (LL)cnt[ans[xl]]*(LL)cnt[ans[xl]];
                cnt[ans[xl]]--;
                sum = sum + (LL)cnt[ans[xl]]*(LL)cnt[ans[xl]];
                xl++;
            }
            while(xl > ask[i].l)
            {
                xl--;sum = sum - (LL)cnt[ans[xl]]*(LL)cnt[ans[xl]];
                cnt[ans[xl]]++;
                sum = sum + (LL)cnt[ans[xl]]*(LL)cnt[ans[xl]];
            }
        LL hi = sum - (ask[i].r-ask[i].l+1);
        LL low = (LL)(ask[i].r-ask[i].l+1)*(LL)(ask[i].r-ask[i].l);
        LL x = gcd(hi,low);
        answer[ask[i].id].l = hi/x;
        answer[ask[i].id].r = low/x;
    }
}
LL gcd(LL n, LL m)
{
    if(m==0)
        return n;
    else return gcd(m,n%m);
}
