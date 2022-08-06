#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;
inline ll mul(ll a,ll b,ll m){
  ll r=((long double)a/m*b+0.5);
  r=a*b-r*m;
  return r<0?r+m:r;
}
ll powM(ll a,ll t,ll m)
{
  ll ans=1;
  while(t){
      if (t&1)ans=mul(ans,a,m);
      a=mul(a,a,m);
      t>>=1;
  }return ans; 
}
bool mr(ll n,ll a)
{
  ll t=n-1;
  while(!(t&1))t>>=1;
  ll buf=powM(a,t,n);
  if (buf==1||buf==n-1)return 0;
  while((t<<=1)<n-1){
    buf=mul(buf,buf,n);
    if (buf==n-1)return 0;
  }return 1;
}
const int testp[8]={2,3,5,7,13,19,61,233};
bool ptest(ll n)
{
  if (n<2)return 0;
  for (int i=2;i*i<=min(n,10000ll);i++)
    if (n%i==0)return 0;
  if (n<=10000)return 1;
  for (int i=0;i<8;i++)
    if (mr(n,testp[i]))return 0;
  return 1;
}
inline ll gcd(ll a,ll b){
  if(a==0)return b;
  if(a<0)a=-a;
  ll t;
  while(b){t=a%b;a=b;b=t;}
  return a;
}
ll sav[150];int tot;
const int lim=128;
ll prho(ll n,ll c)
{
  ll x1=(c+1)%n,x2=(mul(x1,x1,n)+c)%n,buf;
  tot=0;
  while(1){
    buf=mul(x1-x2,buf,n);
    sav[++tot]=x1-x2;
    if (tot==lim){
      if (gcd(buf,n)>1)break;
      tot=0;
    }
    x1=mul(x1,x1,n)+c;
    x2=mul(x2,x2,n)+c;
    x2=mul(x2,x2,n)+c;
  }
  for (int i=1;i<=tot;i++){
    buf=gcd(sav[i],n);
    if (buf>1)return buf;
  }return n;
}
long long ans;
void solve(ll n)
{
  if (n<=ans)return ;
  if (ptest(n)){ans=max(ans,n);return ;}
  ll sav=prho(n,rand()%(n-1)+1);
  while(sav==n)sav=prho(n,rand()%(n-1)+1);
  solve(sav);solve(n/sav);
}
int main()
{
  srand(233);
  int T;scanf("%d",&T);
  for (int qt=1;qt<=T;qt++){
    ll a,sav;
      scanf("%lld",&a);
      if (ptest(a)){
      puts("Prime");
      continue;
    }sav=a;ans=0;
      for (int i=2;i*i<min(10000ll,a);i++)
        if (a%i==0){
          ans=i;
          while(a%i==0)a/=i;
      }
      solve(a);
    printf("%lld\n",ans);
  }return 0;
}