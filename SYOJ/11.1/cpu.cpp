#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#define int long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
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
const int N=20004;
int T,n,mi,ma;
struct node{
    int s,t,w;
    bool operator <(const node &x)const{
        if(s==x.s) return t<x.t;
        return s<x.s;
    }
}a[N];
vector<int> p[N];
typedef pair<int,int> pii;
int W[N];
inline bool check(int x){
    for(int i=1;i<=n;++i) W[i]=a[i].w;
    priority_queue<pii,vector<pii>,greater<pii> > q;
    pii v;
    for(int i=mi;i<ma;++i){
        for(int j:p[i]) q.emplace((pii){a[j].t-1,j});
        v=q.top();
        if(i>v.first){
            // debug(i);
            // debug(v.first);
            if(W[v.second]) return 0;
        }
        if(W[v.second]){
            int tmp=x;
            while(tmp&&q.size()){
                v=q.top();
                if(W[v.second]>tmp){
                    W[v.second]-=tmp;
                    tmp=0;
                }
                else{
                    tmp-=W[v.second];
                    W[v.second]=0;
                    q.pop();
                }
            }
        }
        // if(!W[v.second]){
        //     if(q.size()) q.pop();
        // }
    }
    bool flag=1;
    while(q.size()){
        if(W[q.top().second]){
            flag=0;
            break;
        }
        q.pop();
    }
    return flag;
}
signed main()
{
    // freopen("cpu.in","r",stdin);
    T=read();
    while(T--){
        for(int i=0;i<N;++i) p[i].clear();
        n=read();
        int l=1,r=0;
        mi=1145141919,ma=0;
        for(int i=1;i<=n;++i){
            a[i].s=read();
            mi=min(mi,a[i].s);
            a[i].t=read();
            ma=max(ma,a[i].t);
            a[i].w=read();
            r+=a[i].w;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;++i)
            p[a[i].s].push_back(i);
        int ans=0,mid=0;
        while(l<=r){
            mid=(l+r)>>1;
            // debug(mid);
            if(check(mid)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
1
5
1 4 2
3 6 3
4 5 2
4 7 2
5 8 1
*/