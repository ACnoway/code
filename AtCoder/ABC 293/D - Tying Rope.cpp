#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
int n,m,a,b,ans;
string tmp;
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
    cin>>n>>m;
    for(int i=0;i<=n;++i) p[i]=i;
    for(int i=1;i<=m;++i){
        cin>>a>>tmp>>b>>tmp;
        a=find(a);
        b=find(b);
        if(a==b) ans++;
        else merge(a,b);
    }
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(p[i]==i) cnt++;
    }
    cout<<ans<<' '<<cnt-ans<<endl;
    return 0;
}