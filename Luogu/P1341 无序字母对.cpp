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
const int N=128,M=3003;
int n,ma,mi=N,top;
char st[M];
string s;
int du[N],nxt[N];
bool vis[N];
vector<int> e[N];
void dfs(int x){
    for(int i=nxt[x];i<e[x].size();i=nxt[x]){
        nxt[x]=i+1;
        dfs(e[x][i]);
    }
    st[++top]=x+'A';
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
    for(int i=1;i<=n;++i){
        cin>>s;
        int u=s[0]-'A',v=s[1]-'A';
        ma=max(ma,max(u,v));
        mi=min(mi,min(u,v));
        du[u]++;
        du[v]++;
        e[u].push_back(v);
        e[v].push_back(u);
        merge(u,v);
    }
    for(int i=mi;i<=ma;++i){
        sort(e[i].begin(),e[i].end());
    }
    bool flag=0;
    int cnt=0,stt=0;
    debug(mi);
    debug(ma);
    for(int i=mi;i<=ma;++i){
        if(p[i]==i&&du[i]){
            if(flag){
                flag=0;
                break;
            }
            flag=1;
        }
    }
    if(!flag&&cnt>2){
        puts("No Solution\n");
        return 0;
    }
    dfs(stt);
    debug(top);
    while(top){
        putchar(st[top]);
        top--;
    }
    return 0;
}