#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void write(long long x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=500005;
int n;
int rk[maxn],t[maxn],;
string aa,b;
struct node{
    int num;
    char val;
}a[maxn];
inline int lowbit(int x){
    return x&(-x);
}
bool cmp(node a,node b){
    if(a.val==b.val)
        return a.num<b.num;
    return a.val<b.val;
}
void insert(int x,int v){
    for(;x<=n;x+=lowbit(x))
        t[x]+=v;
}
int query(int x){
    int sum=0;
    for(;x;x-=lowbit(x))
        sum+=t[x];
    return sum;
}
int main()
{
    n=read();
    cin>>aa>>b;
    for(int i=0;i<b.size();++i)
    for(int i=1;i<=n;++i){
        a[i].val=aa[i-1];
        a[i].num=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;++i){
        rk[a[i].num]=i;
    }
    long long ans=0;
    for(int i=1;i<=n;++i){
        insert(rk[i],1);
        ans+=i-query(rk[i]);
    }
    write(ans);
    putchar('\n');
    return 0;
}