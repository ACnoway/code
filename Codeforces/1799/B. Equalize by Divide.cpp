#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
int t,n,ma,mp,mma,mmp,ans,flag;
bool same;
int a[10003],q[10003][3];
signed main()
{
    t=read();
    while(t--){
        n=read();
        ans=0;
        flag=0;
        same=1;
        for(int i=1;i<=n;++i){
            a[i]=read();
            if(i>1&&a[i]!=a[i-1]) same=0;
            if(a[i]!=1) flag++;
        }
        if(flag!=n&&flag){
            write(-1);
            putchar('\n');
            continue;
        }
        if(same){
            write(0);
            putchar('\n');
            continue;
        }
        while(1){
            ma=mma=0;
            for(int i=1;i<=n;++i){
                if(a[i]>a[ma]){
                    mma=ma;
                    ma=i;
                }
                else if(a[i]<a[ma]&&a[i]>a[mma]){
                    mma=i;
                }
            }
            if(mma==0) break;
            q[++ans][0]=ma;
            q[ans][1]=mma;
            a[ma]=a[ma]/a[mma]+(a[ma]%a[mma]==0?0:1);
        }
        write(ans);
        putchar('\n');
        for(int i=1;i<=ans;++i){
            write(q[i][0]);
            putchar(' ');
            write(q[i][1]);
            putchar('\n');
        }
    }
    return 0;
}