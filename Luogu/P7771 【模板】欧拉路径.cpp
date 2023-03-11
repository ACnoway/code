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
const int N=100005,M=200005;
int n,m;
int top,st[M];
int ru[N],chu[N],nxt[N];
vector<int> e[N];
void dfs(int x){
    for(int i=nxt[x];i<e[x].size();i=nxt[x]){
        nxt[x]=i+1;
        dfs(e[x][i]);
    }
    st[++top]=x;
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        ru[v]++;
        chu[u]++;
        e[u].push_back(v);
    }
    for(int i=1;i<=n;++i){
        sort(e[i].begin(),e[i].end());
    }
    int stt=1,cnt1=0,cnt2=0;
    bool flag=1;
    for(int i=1;i<=n;++i){
        if(ru[i]!=chu[i]){
            flag=0;
            if(chu[i]-1==ru[i]) cnt1++,stt=i;
            else if(ru[i]-1==chu[i]) cnt2++;
            else{
                puts("No");
                return 0;
            }
        }
    }
    if(!flag){
        if(!(cnt1==cnt2&&cnt1==1)){
            puts("No");
            return 0;
        }
    }
    dfs(stt);
    while(top){
        printf("%d ",st[top]);
        top--;
    }
    return 0;
}