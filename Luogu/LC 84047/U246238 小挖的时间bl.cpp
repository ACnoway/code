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
int a[15][70];
int d,t,ans,tt;
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
int main()
{
    freopen("wa.in","r",stdin);
    freopen("wabl.out","w",stdout);
    d=read();
    int h,m;
    while(d--){
        h=12;
        m=0;
        t=read();
        ans=0;
        for(int i=1;i<=t;++i){
            m++;
            h+=m/60;
            m%=60;
            if(h==13) h=1;
            if(h>=10){
                if(h%10-h/10==m/10-h%10&&m/10-h%10==m%10-m/10) ans++;
            }
            else{
                if(m/10-h%10==m%10-m/10) ans++;
            }
        }
        write(ans);
        putchar('\n');
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}