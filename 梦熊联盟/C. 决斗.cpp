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
const int N=100005;
int n,ma;
int a[N],b[N],ans[N];
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i) b[i]=read();
    sort(b+1,b+n+1,cmp);
    do{
        int cnt=0;
        for(int i=1;i<=n;++i){
            if(b[i]>a[i]) ++cnt;
        }
        if(cnt>ma){
            ma=cnt;
            for(int i=1;i<=n;++i) ans[i]=b[i];
        }
    }while(prev_permutation(b+1,b+n+1));
    for(int i=1;i<=n;++i) printf("%d ",ans[i]);
    putchar('\n');
    return 0;
}