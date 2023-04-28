#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
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
int T,n,ma,x;
bool vis[10004];
vector<int> ps;
map<int,int> m;
int main()
{
    T=read();
    while(T--){
        ma=0;
        n=read();
        for(int i=1;i<=n;++i){
            x=read();
            for(int j=2;j<=x;++j){
                while(x%j==0){
                    ++c[j];
                    x/=j;
                }
                if(c[j]) ma=max(ma,j);
            }
        }
        int ans=0,lft=0;
        for(int i=2;i<=ma;++i){
            if(!c[i]) continue;
            if(lft){
                ans+=lft/3;
                lft%=3;
            }
            ans+=c[i]/2;
            lft+=c[i]%2;
            c[i]=0;
        }
        if(lft){
            ans+=lft/3;
            lft%=3;
        }
        printf("%d\n",ans);
    }
    return 0;
}