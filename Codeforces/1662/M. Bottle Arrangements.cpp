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
    int r,w,all;
}a[105];
bool cmp(node a,node b){
    return a.all>b.all;
}
int t,n,m;
string s="";
int main()
{
    t=read();
    while(t--){
        s="";
        for(int i=0;i<105;++i){
            a[i].all=0;
            a[i].r=0;
            a[i].w=0;
        }
        n=read();
        m=read();
        for(int i=1;i<=m;++i){
            a[i].r=read();
            a[i].w=read();
            a[i].all=a[i].r+a[i].w;
        }
        sort(a+1,a+1+m,cmp);
        for(int i=1;i<=m;++i){
            
        }
    }
    return 0;
}