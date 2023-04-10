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
const int N=200005;
int T,n,m;
long long sum;
int v[N],t[N],col[N];
vector<int> e[N];
bool flag,vis[N];
void dfs(int x){
    for(auto to:e[x]){
        if(!vis[to]){
            vis[to]=1;
            col[to]=col[x]^1;
            dfs(to);
        }
        else if(col[to]==col[x]){
            flag=0;
            return;
        }
    }
}
int main()
{
    T=read();
    while(T--){
        n=read(); m=read();
        sum=0; flag=1;
        for(int i=0;i<=n;++i){
            vis[i]=0;
            col[i]=-1;
            e[i].clear();
        }
        for(int i=1;i<=n;++i){
            v[i]=read();
            sum+=v[i];
        }
        for(int i=1;i<=n;++i){
            t[i]=read();
            sum-=t[i];
        }
        for(int i=1;i<=m;++i){
            int x=read(),y=read();
            e[x].push_back(y);
            e[y].push_back(x);
        }
        if(sum%2){
            cout<<"NO"<<endl;
            continue;
        }
        col[1]=0;
        dfs(1);
        sum=0;
        for(int i=1;i<=n;++i){
            if(col[i]){
                sum+=v[i]-t[i];
            }
            else{
                sum+=t[i]-v[i];
            }
        }
        if(flag&&sum){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
    return 0;
}