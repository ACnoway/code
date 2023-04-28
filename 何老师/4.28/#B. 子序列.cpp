#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#define int long long
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
const int N=50;
int n,m;
int a[N];
set<int> sa,sb;
void dfs(int x,int sum,int r,set<int> &s){
    if(x>r){
        s.insert(sum%m);
        return;
    }
    dfs(x+1,sum,r,s);
    dfs(x+1,sum+a[x],r,s);
}
signed main()
{
    n=read(); m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int mid=n>>1;
    dfs(1,0,mid,sa);
    dfs(mid+1,0,n,sb);
    int ans=0;
    for(int i:sa){
        int tmp=m-1-i;
        while(tmp){
            if(sb.find(tmp)!=sb.end()) break;
            --tmp;
        }
        ans=max(ans,i+tmp);
    }
    cout<<ans<<endl;
    return 0;
}