#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
const int N=100005,M=21,inf=1000000009;
//  正数最大   正数最小   负数最大    负数最小
int azd[N][M],azx[N][M],afd[N][M],afx[N][M];
int bzd[N][M],bzx[N][M],bfd[N][M],bfx[N][M];
int n,m,q,l1,r1,l2,r2;
int a[N],b[N],Log2[N];
signed main()
{
    n=read();m=read();q=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        azd[i][0]=-1;azx[i][0]=inf;
        afx[i][0]=1;afd[i][0]=-inf;
        if(a[i]>=0) azd[i][0]=azx[i][0]=a[i];
        else if(a[i]<0) afd[i][0]=afx[i][0]=a[i];
    }
    for(int i=1;i<=m;++i){
        b[i]=read();
        bzd[i][0]=-1;bzx[i][0]=inf;
        bfx[i][0]=1;bfd[i][0]=-inf;
        if(b[i]>=0) bzd[i][0]=bzx[i][0]=b[i];
        else if(b[i]<0) bfd[i][0]=bfx[i][0]=b[i];
    }
    for (int i = 2; i <= max(n,m); ++i)
        Log2[i] = Log2[i / 2] + 1;
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j + (1 << i) - 1 <= n; ++j){
            azd[j][i] = max(azd[j][i - 1], azd[j + (1 << (i - 1))][i - 1]);
            afd[j][i] = max(afd[j][i - 1], afd[j + (1 << (i - 1))][i - 1]);
        }
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j + (1 << i) - 1 <= n; ++j){
            azx[j][i] = min(azx[j][i - 1], azx[j + (1 << (i - 1))][i - 1]);
            afx[j][i] = min(afx[j][i - 1], afx[j + (1 << (i - 1))][i - 1]);
        }
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j + (1 << i) - 1 <= m; ++j){
            bzd[j][i] = max(bzd[j][i - 1], bzd[j + (1 << (i - 1))][i - 1]);
            bfd[j][i] = max(bfd[j][i - 1], bfd[j + (1 << (i - 1))][i - 1]);
        }
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j + (1 << i) - 1 <= m; ++j){
            bzx[j][i] = min(bzx[j][i - 1], bzx[j + (1 << (i - 1))][i - 1]);
            bfx[j][i] = min(bfx[j][i - 1], bfx[j + (1 << (i - 1))][i - 1]);
        }
    int aazd,aazx,aafd,aafx;
    int bbzd,bbzx,bbfd,bbfx;
    int sa,sb;
    while(q--){
        l1=read();r1=read();
        l2=read();r2=read();
        sa=Log2[r1-l1+1];
        sb=Log2[r2-l2+1];
        aazd=max(azd[l1][sa], azd[r1 - (1 << sa) + 1][sa]);
        aazx=min(azx[l1][sa], azx[r1 - (1 << sa) + 1][sa]);
        aafd=max(afd[l1][sa], afd[r1 - (1 << sa) + 1][sa]);
        aafx=min(afx[l1][sa], afx[r1 - (1 << sa) + 1][sa]);
        bbzd=max(bzd[l2][sb], bzd[r2 - (1 << sb) + 1][sb]);
        bbzx=min(bzx[l2][sb], bzx[r2 - (1 << sb) + 1][sb]);
        bbfd=max(bfd[l2][sb], bfd[r2 - (1 << sb) + 1][sb]);
        bbfx=min(bfx[l2][sb], bfx[r2 - (1 << sb) + 1][sb]);
        debug(aazd);debug(aazx);debug(aafd);debug(aafx);
        debug(bbzd);debug(bbzx);debug(bbfd);debug(bbfx);
        if(bbzd==-1){
            if(aafx==1) write(aazx*bbfx);
            else write(aafx*bbfd);
        }
        else if(bbfx==1){
            if(aazd==-1) write(aafd*bbzd);
            else write(aazd*bbzx);
        }
        else{
            if(aazd==-1) write(aafd*bbzd);
            else if(aafx==1) write(aazx*bbfx);
            else write(max(aafd*bbzd,aazx*bbfx));
        }
        putchar('\n');
    }
    return 0;
}