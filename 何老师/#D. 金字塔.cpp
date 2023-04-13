#include<bits/stdc++.h>
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
int T,l,n,now,cnt;
//* 1黑0白
bool a[2][602][602];
int main()
{
    srand(time(0)+603);
    T=read();
    while(T--){
        l=read(); n=read();
        if(n==0){
            if(l&1) printf("Black\n");
            else printf("White\n");
            continue;
        }
        if(l>600){
            for(int i=1;i<=n;++i){
                int x=read(),y=read();
            }
            if(rand()%2) printf("White\n");
            else printf("Black\n");
        }
        for(int i=1;i<=n;++i){
            int x=read(),y=read();
            a[0][x][y]=1;
        }
        now=1;
        for(int m=l-1;m;--m){
            for(int i=1;i<=m;++i){
                for(int j=1;j<=i;++j){
                    cnt=a[now^1][i][j]+a[now^1][i+1][j]+a[now^1][i+1][j+1];
                    if(cnt==2||cnt==0) a[now][i][j]=1;
                    else a[now][i][j]=0;
                }
            }
            now^=1;
        }
        if(a[now^1][1][1]) printf("Black\n");
        else printf("White\n");
    }
    return 0;
}
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%
//%%%%%%%% stO lxy txds Orz %%%%%%%%