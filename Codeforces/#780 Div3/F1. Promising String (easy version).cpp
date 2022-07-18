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
inline char rc(){
    char c=getchar();
    while(c!='+'&&c!='-') c=getchar();
    return c;
}
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int m[5000],a[5000];
int t,n;
int main()
{
    t=read();
    while(t--){
        n=read();
        for(int i=1;i<=n;++i){
            char temp=rc();
            a[i]=a[i-1];
            m[i]=m[i-1];
            if(temp=='+') a[i]++;
            else m[i]++;
        }
        int ans=0;
        for(int i=1;i<n;++i){
            for(int j=i+1;j<=n;++j){
                if(a[j]-a[i-1]>m[j]-m[i-1]) continue;
                if((m[j]-m[i-1]-a[j]+a[i-1])%3==0) ans++;
            }
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}