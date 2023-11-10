#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
int n,m,l,ans;
int nian[N],fa[N],pre[N],nxt[N];
bool yes[N<<1];
typedef pair<int,int> pii;
vector<pii> v;
void shan(int x){
    pre[nxt[x]]=pre[x];
    nxt[pre[x]]=nxt[x];
}
void hui(int x){
    pre[nxt[x]]=x;
    nxt[pre[x]]=x;
}
void dfs(int x){
    if(x>=v.size()){
        int tmp=0;
        for(pii i:v){
            for(int j=i.first;j<=i.second;++j) tmp+=yes[j];
        }
        ans=max(ans,tmp);
        return;
    }
    if(pre[x]!=0){
        //left
        pii tmp=v[x];
        int lenn=tmp.second-tmp.first+1;
        v[x]={0,0};
        v[pre[x]].second+=lenn;
        shan(x);
        dfs(x+1);
        hui(x);
        v[pre[x]].second-=lenn;
        v[x]=tmp;
    }
    if(nxt[x]!=v.size()){
        //right
        pii tmp=v[x];
        int lenn=tmp.second-tmp.first+1;
        v[x]={0,0};
        v[nxt[x]].first-=lenn;
        shan(x);
        dfs(x+1);
        hui(x);
        v[nxt[x]].first+=lenn;
        v[x]=tmp;
    }
    dfs(x+1);
}
int main()
{
    freopen("sticky.in","r",stdin);
    freopen("sticky.out","w",stdout);
    n=read();
    m=read();
    l=read();
    for(int i=1;i<=n;++i) pre[i]=i-1,nxt[i]=i+1;
    for(int i=1;i<=n;++i) nian[i]=read();
    for(int i=1;i<=m;++i) fa[i]=read(),yes[fa[i]]=1;
    sort(nian+1,nian+n+1);
    sort(fa+1,fa+n+1);
    int nl=nian[1],nr=nian[1];
    v.push_back({0,0});
    for(int i=2;i<=n;++i){
        if(nian[i]==nian[i-1]+1){
            nr=nian[i];
        }
        else{
            v.push_back({nl,nr});
            nl=nr=nian[i];
        }
    }
    v.push_back({nl,nr});
    // printf("%d\n",m);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}