#include <iostream>
#include <cstdio>
#include <algorithm>
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
struct node{
    int s,e;
    bool operator < (const node &x) const{
        return s<x.s;
    }
}pn[100005],pw[100005];
int n,mn,mw,c1,c2,ans;
int a1[100005][2],a2[100005][2];
int main()
{
    n=read();
    mn=read();
    mw=read();
    for(int i=1;i<=mn;++i) pn[i].s=read(),pn[i].e=read();
    for(int i=1;i<=mw;++i) pw[i].s=read(),pw[i].e=read();
    sort(pn+1,pn+mn+1);
    sort(pw+1,pw+mw+1);
    int st,en;
    bool flag;
    for(int i=1;i<=mn;++i){
        st=pn[i].s;en=pn[i].e;
        flag=false;
        for(int j=1;j<=c1;++j){
            if(st>a1[j][1]){
                a1[j][1]=en;
                a1[j][0]++;
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
        st=pw[i].s;en=pw[i].e;
        flag=false;
        for(int j=1;j<=c2;++j){
            if(st>a2[j][1]){
                a2[j][1]=en;
                a2[j][0]++;
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
    for(int i=0;i<=n;++i){
        ans=max(a1[i][0]+a2[n-i][0],ans);
    }
    write(ans);
    putchar('\n');
    return 0;
}