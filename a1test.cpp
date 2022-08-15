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
int n,mn,mw,c1,c2,ans;
int a1[100005][2],a2[100005][2];
int main()
{
    n=read();
    mn=read();
    mw=read();
    for(int i=1;i<=mn;++i){
        int st=read(),en=read();
        bool flag=false;
        for(int i=1;i<=c1;++i){
            if(st>a1[i][1]){
                a1[i][1]=en;
                a1[i][0]++;
                flag=true;
                break;
            }
        }
        if(!flag){
            a1[++c1][1]=en;
            a1[c1][0]++;
        }
    }
    for(int i=1;i<=mw;++i){
        int st=read(),en=read();
        bool flag=false;
        for(int i=1;i<=c2;++i){
            if(st>a2[i][1]){
                a2[i][1]=en;
                a2[i][0]++;
                flag=true;
                break;
            }
        }
        if(!flag){
            a2[++c2][1]=en;
            a2[c2][0]++;
        }
    }
    for(int i=1;i<=n;++i){
        a1[i][0]+=a1[i-1][0];
        a2[i][0]+=a2[i-1][0];
    }
    for(int i=1;i<=n;++i){
        ans=max(a1[i][0]+a2[n-i][0],ans);
    }
    cout<<ans<<endl;
    return 0;
}