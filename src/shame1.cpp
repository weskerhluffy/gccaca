#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cctype>
#define rd(x) scanf("%d",&x)
#define rd2(x,y)  scanf("%d%d",&x,&y)
#define rd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
using namespace std;
typedef long long ll;
const int maxn=1002;
int prime[maxn+1];
void getPrime()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=maxn;i++)
    {
        if(!prime[i])
            prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=maxn/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
 
int factor[100][2];
int fatcnt;
int getFactors(int x)
{
    fatcnt=0;
    int tmp=x;
    for(int i=1;prime[i]<=tmp/prime[i];i++)
    {
        factor[fatcnt][1]=0;
        if(tmp%prime[i]==0)
        {
            factor[fatcnt][0]=prime[i];
            while(tmp%prime[i]==0)
            {
                factor[fatcnt][1]++;
                tmp/=prime[i];
            }
            fatcnt++;
        }
    }
    if(tmp!=1)
    {
        factor[fatcnt][0]=tmp;
        factor[fatcnt++][1]=1;
    }
    return fatcnt;
}
 
const int MAXN=100010;
int euler[MAXN+1];
void getEuler()
{
    memset(euler,0,sizeof(euler));
    euler[1]=1;
    for(int i=2;i<=MAXN;i++)
    {
        if(!euler[i])
            for(int j=i;j<=MAXN;j+=i)
        {
            if(!euler[j])
                euler[j]=j;
            euler[j]=euler[j]/i*(i-1);
        }
    }
}
 
int t,cas=1;
int a,b,c,d,k;
long long ans;
 
int cal(int n,int m)//计算1~n里面有多少个数和m互质
{
    getFactors(m);
    int ans=0;
    for(int s=1;s<(1<<fatcnt);s++)//直接枚举二进制位
    {
        int k=0;//重叠几次
        int lcm=1;
        for(int j=0;j<fatcnt;j++)
        {
            if(s&(1<<j))
            {
                k++;
                lcm*=factor[j][0];//因为都是素数，最小公倍数就是他们的乘积
            }
        }
        if(k&1)
            ans+=n/lcm;
        else
            ans-=n/lcm;
    }
    return n-ans;
}
 
int main()
{
    rd(t);
    getPrime();
    getEuler();
    while(t--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k==0||k>b||k>d)
        {
            printf("Case %d: %I64d\n",cas++,0);
            continue;
        }
        if(b>d)
            swap(b,d);
        b/=k,d/=k;
        ans=0;
        for(int i=1;i<=b;i++)
            ans+=euler[i];
        for(int i=b+1;i<=d;i++)
            ans+=cal(b,i);
        printf("Case %d: %I64d\n",cas++,ans);
    }
    return 0;
}

