//单点修改，区间查询
inline void build(int i,int l,int r){//递归建树
    tree[i].l=l;tree[i].r=r;
    if(l==r){//如果这个节点是叶子节点
        tree[i].sum=input[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(i*2,l,mid);//分别构造左子树和右子树
    build(i*2+1,mid+1,r);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;//刚才我们发现的性质return ;
}
inline int search(int i,int l,int r){
    //如果这个区间被完全包括在目标区间里面，直接返回这个区间的值
    if(tree[i].l>=l && tree[i].r<=r)
        return tree[i].sum;
    //如果这个区间和目标区间毫不相干，返回0
    if(tree[i].r<l || tree[i].l>r)  return 0;
    int s=0;
    //如果这个区间的左儿子和目标区间有交集，那么搜索左儿子
    if(tree[i*2].r>=l)  s+=search(i*2,l,r);
    //如果这个区间的右儿子和目标区间有交集，那么搜索右儿子
    if(tree[i*2+1].l<=r)  s+=search(i*2+1,l,r);
    return s;
}
inline void add(int i,int dis,int k){
    if(tree[i].l==tree[i].r){//如果是叶子节点，那么说明找到了
        tree[i].sum+=k;
        return ;
    }
    if(dis<=tree[i*2].r)  add(i*2,dis,k);//在哪往哪跑
    else  add(i*2+1,dis,k);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;//返回更新
    return ;
}

//单点查询，区间修改
inline void add(int i,int l,int r,int k){
    if(tree[i].l>=l && tree[i].r<=r){//如果这个区间被完全包括在目标区间里面，讲这个区间标记k
        tree[i].sum+=k;
        return ;
    }
    if(tree[i*2].r>=l)
        add(i*2,l,r,k);
    if(tree[i*2+1].l<=r)
        add(i*2+1,l,r,k);
}
void search(int i,int dis){
    ans+=tree[i].num;//一路加起来
    if(tree[i].l==tree[i].r)
        return ;
    if(dis<=tree[i*2].r)
        search(i*2,dis);
    if(dis>=tree[i*2+1].l)
        search(i*2+1,dis);
}

//pushdown区间修改查询，区间加
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define init long long
using namespace std;
init n,m;
struct node
{
    init l,r,data;
    init lt;    
}tree[1000010];
init arr[1000010];
void build(init l,init r,init index)
{
    tree[index].lt=0;
    tree[index].l=l;
    tree[index].r=r;
    if(l==r)
    {
        tree[index].data=arr[l];
        return ;
    }
    init mid=(l+r)/2;
    build(l,mid,index*2);
    build(mid+1,r,index*2+1);
    tree[index].data=tree[index*2].data+tree[index*2+1].data;
    return ;
}
void push_down(init index)
{
    if(tree[index].lt!=0)
    {
        //传递lazytag
        tree[index*2].lt+=tree[index].lt;
        tree[index*2+1].lt+=tree[index].lt;
        //计算影响
        init mid=(tree[index].l+tree[index].r)/2;
        tree[index*2].data+=tree[index].lt*(mid-tree[index*2].l+1);
        tree[index*2+1].data+=tree[index].lt*(tree[index*2+1].r-mid);
        tree[index].lt=0;
    }
    return ;
}
void up_data(init index,init l,init r,init k)
{
    if(tree[index].l>=l && tree[index].r<=r)
    {
        tree[index].data+=k*(tree[index].r-tree[index].l+1);
        tree[index].lt+=k;
        return ;
    }
    push_down(index);
    if(tree[index*2].r>=l)
        up_data(index*2,l,r,k);
    if(tree[index*2+1].l<=r)
        up_data(index*2+1,l,r,k);
    tree[index].data=tree[index*2].data+tree[index*2+1].data;
    return ;
}
init search(init index,init l,init r)
{
    if(tree[index].l>=l && tree[index].r<=r)
        return tree[index].data;
    push_down(index);
    init num=0;
    if(tree[index*2].r>=l)
        num+=search(index*2,l,r);
    if(tree[index*2+1].l<=r)
        num+=search(index*2+1,l,r);
    return num;
}
int main()
{
    cin>>n>>m;
    for(init i=1;i<=n;i++)
        cin>>arr[i];
    build(1,n,1,arr);
    for(init i=1;i<=m;i++)
    {
        init f;
        cin>>f;
        if(f==1)
        {
            init a,b,c;
            cin>>a>>b>>c;
            up_data(1,a,b,c);
        }
        if(f==2)
        {
            init a,b;
            cin>>a>>b;
            printf("%lld\n",search(1,a,b));
        }
    }
}

//区间查询，区间乘
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
#define MAXN 100010
#define INF 10000009
#define MOD 10000007
#define LL long long
#define in(a) a=read()
#define REP(i,k,n) for(long long i=k;i<=n;i++)
#define DREP(i,k,n) for(long long i=k;i>=n;i--)
#define cl(a) memset(a,0,sizeof(a))
inline long long read(){
    long long x=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
    return x*f;
}
inline void out(long long x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) out(x/10);
    putchar(x%10+'0');
}
long long n,m,p;
long long input[MAXN];
struct node{
    long long l,r;
    long long sum,mlz,plz;
}tree[4*MAXN];
inline void build(long long i,long long l,long long r){
    tree[i].l=l;
    tree[i].r=r;
    tree[i].mlz=1;
    if(l==r){
        tree[i].sum=input[l]%p;
        return ;
    }
    long long mid=(l+r)>>1;
    build(i<<1,l,mid);
    build(i<<1|1,mid+1,r);
    tree[i].sum=(tree[i<<1].sum+tree[i<<1|1].sum)%p;
    return ;
}
inline void pushdown(long long i){
    long long k1=tree[i].mlz,k2=tree[i].plz;
    tree[i<<1].sum=(tree[i<<1].sum*k1+k2*(tree[i<<1].r-tree[i<<1].l+1))%p;
    tree[i<<1|1].sum=(tree[i<<1|1].sum*k1+k2*(tree[i<<1|1].r-tree[i<<1|1].l+1))%p;
    tree[i<<1].mlz=(tree[i<<1].mlz*k1)%p;
    tree[i<<1|1].mlz=(tree[i<<1|1].mlz*k1)%p;
    tree[i<<1].plz=(tree[i<<1].plz*k1+k2)%p;
    tree[i<<1|1].plz=(tree[i<<1|1].plz*k1+k2)%p;
    tree[i].plz=0;
    tree[i].mlz=1;
    return ;
}
inline void mul(long long i,long long l,long long r,long long k){
    if(tree[i].r<l || tree[i].l>r)  return ;
    if(tree[i].l>=l && tree[i].r<=r){
        tree[i].sum=(tree[i].sum*k)%p;
        tree[i].mlz=(tree[i].mlz*k)%p;
        tree[i].plz=(tree[i].plz*k)%p;
        return ;
    }
    pushdown(i);
    if(tree[i<<1].r>=l)  mul(i<<1,l,r,k);
    if(tree[i<<1|1].l<=r)  mul(i<<1|1,l,r,k);
    tree[i].sum=(tree[i<<1].sum+tree[i<<1|1].sum)%p;
    return ;
}
inline void add(long long i,long long l,long long r,long long k){
    if(tree[i].r<l || tree[i].l>r)  return ;
    if(tree[i].l>=l && tree[i].r<=r){
        tree[i].sum+=((tree[i].r-tree[i].l+1)*k)%p;
        tree[i].plz=(tree[i].plz+k)%p;
        return ;
    }
    pushdown(i);
    if(tree[i<<1].r>=l)  add(i<<1,l,r,k);
    if(tree[i<<1|1].l<=r)  add(i<<1|1,l,r,k);
    tree[i].sum=(tree[i<<1].sum+tree[i<<1|1].sum)%p;
    return ;
}
inline long long search(long long i,long long l,long long r){
    if(tree[i].r<l || tree[i].l>r)  return 0;
    if(tree[i].l>=l && tree[i].r<=r)
        return tree[i].sum;
    pushdown(i);
    long long sum=0;
    if(tree[i<<1].r>=l)  sum+=search(i<<1,l,r)%p;
    if(tree[i<<1|1].l<=r)  sum+=search(i<<1|1,l,r)%p;
    return sum%p;
}
int main(){
    in(n);    in(m);in(p);
    REP(i,1,n)  in(input[i]);
    build(1,1,n); 

    REP(i,1,m){
        long long fl,a,b,c;
        in(fl);
        if(fl==1){
            in(a);in(b);in(c);
            c%=p;
            mul(1,a,b,c);
        }
        if(fl==2){
            in(a);in(b);in(c);
            c%=p;
            add(1,a,b,c);
        }
        if(fl==3){
            in(a);in(b);
            printf("%lld\n",search(1,a,b));
        }
    }
    return 0;
}
/*
5 4 1000
1 2 3 4 5
3 1 5
2 1 5 1
1 1 5 2

3 1 5
*/