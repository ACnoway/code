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
const int N=202;
string A,B;
int T,n,m;
int dfid,col,dfn[N],low[N],color[N];
int top,st[N];
vector<int> e[N];
void tarjan(int x){
    dfn[x]=low[x]=++dfid;
    st[++top]=x;
    for(auto v:e[x]){
        if(!dfn[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        else if(!color[v]) low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x]){
        color[x]=++col;
        while(st[top]!=x){
            color[st[top]]=col;
            --top;
        }
        --top;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n>>m;
        dfid=col=top=0;
        for(int i=0;i<=2*n;++i){
            e[i].clear();
            dfn[i]=low[i]=color[i]=0;
        }
        for(int i=1;i<=m;++i){
            int x=0,a,y=0,b;
            cin>>A>>B;
            a=(A[0]=='h');
            for(int i=1;i<A.size();++i){
                x=(x<<3)+(x<<1)+(A[i]^48);
            }
            b=(B[0]=='h');
            for(int i=1;i<B.size();++i){
                y=(y<<3)+(y<<1)+(B[i]^48);
            }
            e[x+(a^1)*n].push_back(y+b*n);
            e[y+(b^1)*n].push_back(x+a*n);
        }
        for(int i=1;i<=2*n;++i){
            if(!dfn[i]) tarjan(i);
        }
        bool flag=0;
        for(int i=1;i<=n;++i){
            if(color[i]==color[i+n]){
                cout<<"BAD"<<endl;
                flag=1;
                break;
            }
        }
        if(flag) continue;
        cout<<"GOOD"<<endl;
    }
    return 0;
}