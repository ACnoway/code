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
    for(int i=1;i<60;++i){
        a[12][i]=a[12][i-1];
        if(i/10-2==1&&i%10-i/10==1) a[12][i]++;
    }
    a[12][60]=a[12][59];
    for(int i=1;i<12;++i){
        for(int j=1;j<60;++j){
            a[i][j]=a[i][j-1];
            if(i>=10){
                if(i%10-i/10==j/10-i%10&&j/10-i%10==j%10-j/10) a[i][j]++;
            }
            else{
                if(j/10-i%10==j%10-j/10) a[i][j]++;
            }
        }
        a[i][60]=a[i][59];
    }
    d=read();
    while(d--){
        t=read();
        ans=0;
        ans+=t/720*31;
        t%=720;
        tt=t/60;
        for(int i=0;i<tt;++i) ans+=a[(12+i)%13+(12+i>=13)][60];
        ans+=a[(12+(tt))%13+(12+(tt)>=13)][t%60];
        write(ans);
        putchar('\n');
    }
    return 0;
}