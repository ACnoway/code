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
typedef pair<int,int> pii;
const int N=200005;
int t,n,x;
int cnt[N];
vector<int> al[N];
struct ma[N];
int main()
{
    t=read();
    while(t--){
        n=read();
        for(int i=1;i<=n;++i){
            al[i].clear();
            cnt[i]=read();
            ma[i].first=0;
            ma[i].second=i;
            for(int j=1;j<=cnt[i];++j){
                x=read();
                ma[i].first=max(ma[i].first,x);
                al[i].push_back(x);
            }
        }
        sort(ma+1,ma+1+n);
        int now=0,ans=0;
        for(int i=1;i<=n;++i){
            x=ma[i].second;
            for(int j=0;j<cnt[x];++j){
                if(now<al[x][j]){
                    now=al[x][j];
                    ++ans;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}