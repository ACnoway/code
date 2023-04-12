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
const int N=1003;
int n,ma;
int a[N],match[N];
bool vis[N];
vector<int> b;
vector<int> e[N*N];
bool dfs(int x){
    for(int i:e[x]){
        if(vis[i]) continue;
        vis[i]=1;
        if(match[i]==-1||dfs(match[i])){
            match[i]=x;
            return 1;
        }
    }
    return 0;
}
int main()
{
    n=read();
    for(int i=0;i<=n;++i) match[i]=-1;
    for(int i=1;i<=n;++i){
        a[i]=read();
        for(int j=1;j<=n;++j){
            b.push_back(a[i]*j);
        }
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    //一个小trick，unique返回的是去重后的end()，然后在原数组中将新end()到旧end()的位置全部删除
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            e[lower_bound(b.begin(),b.end(),a[i]*j)-b.begin()].push_back(i);
        }
    }
    long long ans=0;
    for(int i=0;i<b.size();++i){
        if(dfs(i)){
            ans+=b[i];
            for(int j=0;j<=n;++j) vis[j]=0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}