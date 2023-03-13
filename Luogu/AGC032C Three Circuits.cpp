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
const int N=1000005,M=2000005;
int n,m,a,b;
int vis[N];
vector<int> e[N];
void dfs(int x){
    vis[x]=1;
    for(auto i:e[x]){
        if(vis[i]==2) a?b=i:a=i;//记录相交的点
        else if(!vis[i]) dfs(i);
    }
}
int main()
{
    n=read();
    m=read();
    int x,y;
    for(int i=1;i<=m;++i){
        x=read(); y=read();
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int ma=0,mc=0;
    for(int i=1;i<=n;++i){
        if(e[i].size()&1){
            cout<<"No"<<endl;
            return 0;
        }
        else if(e[i].size()>ma) ma=e[i].size(),mc=1;
        else mc+=(ma==e[i].size());
    }
    if(ma>=6){
        cout<<"Yes"<<endl;
        return 0;
    }
    else if(ma==2||mc==1){
        cout<<"No"<<endl;
        return 0;
    }
    else if(mc>2){
        cout<<"Yes"<<endl;
        return 0;
    }
    else{
        int cnt=0;
        for(int i=1;i<=n;++i){
            if(e[i].size()==4) vis[i]=2;
        }
        for(int i=1;i<=n;++i){
            if(!vis[i]){
                a=b=0;
                dfs(i);
                cnt+=a==b;
            }
        }
        cout<<(cnt?"Yes":"No")<<endl;
    }
    return 0;
}