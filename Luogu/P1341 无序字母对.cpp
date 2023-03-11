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
const int N=260,M=3003;
int n,ma,mi=N,top;
char st[N*N];
string s;
int du[N],nxt[N];
bool vis[N][N];
vector<int> e[N];
void dfs(int x){
    for(auto i:e[x]){
        if(!vis[x][i]){
            vis[x][i]=1;
            vis[i][x]=1;
            dfs(i);
        }
    }
    st[++top]=x;
}
//* -----并查集
int p[N];
int find(int x){
    while(p[x]!=x) x=p[x]=p[p[x]];
    return p[x];
}
void merge(int x,int y){
    p[find(x)]=find(y);
}
int main()
{
    cin>>n;
    for(int i=0;i<N;++i) p[i]=i;
    for(int i=1;i<=n;++i){
        cin>>s;
        int u=s[0],v=s[1];
        ma=max(ma,max(u,v));
        mi=min(mi,min(u,v));
        merge(u,v);
        du[u]++;
        du[v]++;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=mi;i<=ma;++i){
        if(e[i].empty()) continue;
        sort(e[i].begin(),e[i].end());
    }
    int flag=0,cnt=0,stt=0;
    for(int i=mi;i<=ma;++i){
        if(p[i]==i&&du[i]){
            flag++;
        }
    }
    if(flag!=1){
        puts("No Solution\n");
        return 0;
    }
    for(int i=mi;i<=ma;++i){
        if(du[i]&1){
            cnt++;
            if(!stt) stt=i;
        }
    }
    if(!stt){
        for(int i=mi;i<=ma;++i){
            if(du[i]){
                stt=i;
                break;
            }
        }
    }
    if(cnt&&cnt!=2){
        puts("No Solution\n");
        return 0;
    }
    dfs(stt);
    while(top){
        putchar(st[top]);
        top--;
    }
    return 0;
}