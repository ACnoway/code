#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
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
const int N=2e5+10;
int m,cnt,x;
int n[N],ans[N];
bool vis[N];
vector<int> e[N<<1];
map<int,int> pl;
void dfs(int x,int d){
    ans[x]=d;
    vis[x]=1;
    //注意这里选一个进去遍历
    if(!vis[e[x][0]]) dfs(e[x][0],d^1);
    else if(!vis[e[x][1]]) dfs(e[x][1],d^1);
}
int main()
{
    m=read();
    for(int i=1;i<=m;++i){
        n[i]=read();
        for(int j=1;j<=n[i];++j){
            ++cnt;
            x=read();
            if(j%2==0){
                e[cnt].push_back(cnt-1);
                e[cnt-1].push_back(cnt);
            }
            if(pl[x]>0){
                e[cnt].push_back(pl[x]);
                e[pl[x]].push_back(cnt);
                pl.erase(x);
            }
            else pl[x]=cnt;
        }
    }
    if(pl.size()){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=1;i<=cnt;++i){
        if(!vis[i]) dfs(i,0);
    }
    cnt=0;
    cout<<"YES"<<endl;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n[i];++j){
            putchar("LR"[ans[++cnt]]);
        }
        putchar('\n');
    }
    return 0;
}