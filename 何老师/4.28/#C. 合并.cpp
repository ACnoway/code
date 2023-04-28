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
typedef pair<int,int> pii;
const int N=150005,inf=1000000009;
int n;
int a[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
struct node{
    int v,id;
}ans[N];
int cnt;
bool cmp(node a,node b){
    return a.id<b.id;
}
signed main()
{
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        q.emplace((pii){a[i],i});
    }
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(q.empty()){
            ans[++cnt].v=a[u];
            ans[cnt].id=u;
            break;
        }
        if(a[u]!=q.top().first){
            ans[++cnt].v=a[u];
            ans[cnt].id=u;
        }
        else{
            u=q.top().second;
            q.pop();
            a[u]=a[u]*2;
            q.emplace((pii){a[u],u});
        }
    }
    cout<<cnt<<endl;
    sort(ans+1,ans+cnt+1,cmp);
    for(int i=1;i<=cnt;++i){
        cout<<ans[i].v<<' ';
    }
    return 0;
}