#include <iostream>
#include <cstdio>
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
int f[10004],a[101][101];
int n,m,t,ans;
int main()
{
    t=read();
    n=read();
    m=read();
    for(int i=1;i<=t;++i){
        for(int j=1;j<=n;++j) a[i][j]=read();
    }
    ans=m;
    for(int i=1;i<t;++i){
        for(int j=0;j<=10003;++j) f[j]=-1073741820;
        f[ans]=ans;
        for(int j=1;j<=n;++j){
            for(int k=ans;k>=a[i][j];--k){
                f[k-a[i][j]]=max(f[k-a[i][j]],f[k]+a[i+1][j]-a[i][j]);
            }
        }
        int ma=0;
        for(int j=0;j<=ans;++j) ma=max(ma,f[j]);
        ans=ma;
    }
    write(ans);
    return 0;
}