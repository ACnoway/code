#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=50;
int n,mid,ans,sum,t;
int p[20] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int a[maxn];
int lsum[9][10000006],lt,rsum[9][10000006],rt;
void dfs(int x){
    if(x==mid+1){
        lt++;
        for(int i=0;i<9;++i) lsum[i][lt]+=sum%p[i+1];
        return;
    }
    dfs(x+1);
    sum+=a[x];
    dfs(x+1);
    sum-=a[x];
}
void dfs2(int x){
    if(x==mid){
        rt++;
        for(int i=0;i<9;++i) rsum[i][rt]+=sum%p[i+1];
        return;
    }
    dfs2(x-1);
    sum+=a[x];
    dfs2(x-1);
    sum-=a[x];
}
bool cmp(int a,int b){
    return a>b;
}
signed main()
{
    n=read();
    mid=n>>1;
    for(int i=1;i<=n;++i) a[i]=read();
    dfs(1);
    dfs2(n);
    for(int i=0;i<9;++i){
        int cnt=0;
        sort(lsum[i]+1,lsum[i]+1+lt);
        sort(rsum[i]+1,rsum[i]+1+rt);
        int L=1,R=1;
        for(int r=rt;r;--r){
            while(R<=lt&&lsum[i][R]+rsum[i][r]<5*p[i])
                R++;
            while(L<R&&lsum[i][L]+rsum[i][r]<4*p[i])
                L++;
            cnt+=R-L;
        }
        for(int r=rt;r;--r){
            while(R<=lt&&lsum[i][R]+rsum[i][r]<15*p[i])
                R++;
            while(L<R&&lsum[i][L]+rsum[i][r]<14*p[i])
                L++;
            cnt+=R-L;
        }
        ans+=cnt;
    }
    write(ans);
    putchar('\n');
    return 0;
}