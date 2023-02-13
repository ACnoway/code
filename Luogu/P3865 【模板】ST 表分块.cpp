#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=100005;
int n,m,l,r,ans;
int a[maxn],b[maxn],belong[maxn],g[maxn][2];
//belong[i]表示第i个数在第几块
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int kuai=sqrt(n);
    int sum=n/kuai;
    if(n%kuai) sum++;//多出来的一点
    for(int i=1;i<=sum;++i){
        g[i][0]=(i-1)*kuai+1;
        g[i][1]=min(n,i*kuai); //特判防止越界
        debug(g[i][0]);
        debug(g[i][1]);
        for(int j=g[i][0];j<=g[i][1];++j) b[i]=max(b[i],a[j]),belong[j]=i;
    }
    while(m--){
        ans=0;
        l=read();r=read();
        int A=belong[l],B=belong[r];
        if(A<B){
            //如果不在同一个块上就先处理中间的块
            for(int i=A+1;i<B;++i) ans=max(ans,b[i]);
        }
        for(int i=l;i<=min(g[A][1],r);++i) ans=max(ans,a[i]);
        
        write(ans);
        putchar('\n');
    }
    return 0;
}