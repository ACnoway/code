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
const int N=1003;
int n,m,h,ans;
int a[N][N],cnt[N][N];
typedef pair<int,int> pii;
pii st[N];
void calc(int x){
    h=0;
    int tmp=0,ma=0;
    st[++h].first=cnt[x][1];
    st[h].second=1;
    for(int i=2;i<=m;++i){
        tmp=0;
        while(st[h].first>=cnt[x][i]&&h){
            tmp+=st[h].second;
            ma=max(ma,st[h--].first*tmp);
        }
        st[++h]={cnt[x][i],tmp+1};
    }
    tmp=0;
    while(h){
        tmp+=st[h].second;
        ma=max(ma,st[h--].first*tmp);
    }
    ans=max(ans,ma);
}
int main()
{
    freopen("makrix.in","r",stdin);
    freopen("makrix.out","w",stdout);
    n=read(); m=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            a[i][j]=read();
        }
    }
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cnt[i][j]=1;
    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j){
            if(a[i][j]+a[i+1][j+1]<=a[i+1][j]+a[i][j+1]) cnt[i][j]=cnt[i-1][j]+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}