#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=102;
typedef pair<int,int> pii;
int n,m;
int dx[5]={0,-1,-1,1,1},dy[5]={0,-1,1,-1,1};
char c[N][N];
pii p[5];
void bfs(int sx,int sy){
    queue<pii> q;
    pii now;
    q.emplace((pii){sx,sy});
    while(!q.empty()){
        now=q.front();
        q.pop();
        
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>c[i]+1;
    for(int i=2;i<n;++i){
        for(int j=2;j<m;++j){
            bfs(i,j);
        }
    }
    return 0;
}