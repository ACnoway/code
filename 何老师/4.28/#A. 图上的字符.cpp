#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
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
const int N=100005;
int T,n,m,hd,tl;
int a[N],ru[N],q[N];
int f[N][30];
string s;
vector<int> e[N];
bool tuopu(){
    hd=tl=0;
    for(int i=1;i<=n;++i){
        if(!ru[i]) q[++tl]=i;
    }
    int p;
    while(hd<tl){
        p=q[++hd];
        for(int v:e[p]){
            --ru[v];
            if(!ru[v]){
                q[++tl]=v;
            }
        }
    }
    return tl==n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>s;
        for(int i=1;i<=n;++i){
            a[i]=s[i-1]-'a';
            e[i].clear();
            for(int j=0;j<27;++j) f[i][j]=0;
        }
        for(int i=1;i<=m;++i){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            ++ru[v];
        }
        for(int i=1;i<=n;++i){
            if(!ru[i]) f[i][a[i]]=1;
        }
        bool flag=tuopu();
        if(!flag){
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=tl;++i){
            for(int v:e[q[i]]){
                for(int k=0;k<26;++k){
                    f[v][k]=max(f[v][k],f[q[i]][k]+(a[v]==k));
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            for(int j=0;j<26;++j){
                ans=max(ans,f[i][j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}