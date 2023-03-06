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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int n,m,ans;
bool vis[2000003];
vector<int> e[2000003];
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        e[u].push_back(v);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) vis[j]=0;
        int p,y;
        vis[i]=1;
        queue<int> q;
        q.push(i);
        while(q.size()){
            p=q.front();
            q.pop();
            for(int j=0;j<e[p].size();++j){
                y=e[p][j];
                if(vis[y]) continue;
                vis[y]=1;
                q.push(y);
                ans++;
            }
        }
    }
    ans-=m;
    write(ans);
    putchar('\n');
    return 0;
}