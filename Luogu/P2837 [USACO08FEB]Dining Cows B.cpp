#include <iostream>
#include <cstdio>
using namespace std;
int n,ans,a1,a2;
int a[30004],t1[30004],t2[30004];
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
    n=read();
    int c1=0,c2=0,p1=0,p2=0;
    for(int i=1;i<=n;++i){
        a[i]=read();
        t1[i]=t1[i-1];
        t2[i]=t2[i-1];
        if(a[i]==1) t1[i]++;
        else t2[i]++;
        if(t1[i]-t2[i]>c1){
            c1=t1[i]-t2[i];
            p1=i;
        }
        if(t2[i]-t1[i]>c2){
            c2=t2[i]-t1[i];
            p2=i;
        }
    }
    for(int i=1;i<=p1;++i){
        if(a[i]==2) ans++;
    }
    for(int i=p1+1;i<=n;++i){
        if(a[i]==1) ans++;
    }
    write(ans);
    return 0;
}