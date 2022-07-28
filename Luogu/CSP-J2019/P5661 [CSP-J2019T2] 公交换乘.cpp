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
struct ticket
{
    int s,p,k;
}ts[100005],q[100005];
int n,h=1,t,ans;
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        ts[i].k=read();
        ts[i].p=read();
        ts[i].s=read();
        if(ts[i].k==0){
            q[++t]=ts[i];
            ans+=ts[i].p;
            continue;
        }
        while(ts[i].s-q[h].s>45&&h<=t) ++h;
        if(h>t){
            ans+=ts[i].p;
            continue;
        }
        else{
            int j;
            for(j=h;j<=t;++j){
                if(q[j].p>=ts[i].p) break;
            }
            if(j>t){
                ans+=ts[i].p;
            }
            else{
                q[j].p=-1;
            }
        }   
    }
    write(ans);
    return 0;
}