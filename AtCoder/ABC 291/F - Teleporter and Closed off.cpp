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
const int maxn=100005,inf=1047483647;
int n,m;
int qian[maxn],hou[maxn];
char s[maxn][20];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i) cin>>s[i]+1;
    for(int i=0;i<=n+1;++i) qian[i]=hou[i]=inf;
    qian[1]=0;hou[n]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(s[i][j]=='1'){
                qian[i+j]=min(qian[i+j],qian[i]+1);
            }
        }
    }
    for(int i=n;i;--i){
        for(int j=1;j<=m;++j){
            if(s[i][j]=='1'){
                hou[i]=min(hou[i],hou[i+j]+1);
            }
        }
    }
    for(int i=2;i<n;++i){
        for(int j=1;j<=)
    }
    return 0;
}