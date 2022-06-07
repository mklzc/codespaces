#include<bits/stdc++.h>
#define len double(t[p].r-t[p].l+1)
#define db double
#define ls p<<1
#define rs p<<1|1
#define debug cout<<"success: "
using namespace std;
template<class T>
inline void read(T &x)
{
    x=0;
    T w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
        x=x*10+ch-48,ch=getchar();
    x=x*w;
}
const int N=1e5+10;
int n,m;
db a[N];
struct SegmentTree
{
    int l,r;
    db sum,fc,add;
}t[N<<2];
void pushup(int p) {
    t[p].sum=t[ls].sum+t[rs].sum;
    t[p].fc=t[ls].fc+t[rs].fc;
}
void build(int p,int l,int r)
{
    t[p].l=l,t[p].r=r;
    if(l==r){
        t[p].sum=a[l];
        t[p].fc=a[l]*a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
void pushdown(int p) 
{
    if(!t[p].add) return;
    // debug;
    db lenr=t[rs].r-t[rs].l+1,lenl=t[ls].r-t[ls].l+1;
    // fc 
    t[ls].fc+=t[p].add*(lenl*t[p].add+2*t[ls].sum);
    t[rs].fc+=t[p].add*(lenr*t[p].add+2*t[rs].sum);
    // sum
    t[ls].sum+=lenl*t[p].add;
    t[rs].sum+=lenr*t[p].add;
    //add
    t[ls].add+=t[p].add,t[rs].add+=t[p].add;
    t[p].add=0;
}
void modify(int p,int l,int r,db k)
{
    if(t[p].l>=l&&t[p].r<=r) {
        t[p].fc+=k*(len*k+2*t[p].sum);
        t[p].sum+=len*k,t[p].add+=k;
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)>>1;
    if(l<=mid) modify(ls,l,r,k);
    if(r>mid) modify(rs,l,r,k);
    pushup(p);
}
db query_sum(int p,int l,int r) {
    if(t[p].l>=l&&t[p].r<=r)
        return t[p].sum;
    pushdown(p);
    int mid=(t[p].l+t[p].r)>>1;
    db val=0;
    if(l<=mid) val+=query_sum(ls,l,r);
    if(r>mid) val+=query_sum(rs,l,r);
    return val;
}
db query_fc(int p,int l,int r){
    if(t[p].l>=l&&t[p].r<=r){
        // db xi=t[p].fc-(t[p].sum*t[p].sum)/len;
        return t[p].fc;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)>>1;
    db val=0;
    if(l<=mid) val+=query_fc(ls,l,r);
    if(r>mid) val+=query_fc(rs,l,r);
    return val;
}
int main()
{
    read(n),read(m);
    for(int i=1;i<=n;i++)
        scanf("%lf",&a[i]);
    build(1,1,n);
    int op,x,y;
    db k;
    for(int i=1;i<=m;i++)
    {
        read(op);read(x);read(y);
        if(op==1){
            scanf("%lf",&k);
            modify(1,x,y,k);
        }
        else if(op==2)
            printf("%.4lf\n",db(query_sum(1,x,y))/db(y-x+1));
        else if(op==3){
            db fc=query_fc(1,x,y),sum=query_sum(1,x,y),lenth=y-x+1;
            db ans=fc-(sum*sum)/lenth;
            printf("%.4lf\n",ans/lenth);
        }
    }
    return 0;
}