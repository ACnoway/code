#include <iostream>
#include <cstdio>
#include <cmath>
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
int n,a,h,t,hh,tt;
bool v[400000];
int now[400000],nt[400000],f[400000];
int main()
{
    f[0]=0;
    v[0]=true;
    now[t++]=0;
    nt[tt++]=0;
    while(h<t){
        f[now[h]]=nt[h];
        if(!(now[h]&1)){
            if(!v[now[h]>>1]){
                now[t++]=now[h]>>1;
                nt[tt++]=nt[hh]+1;
                v[now[h]>>1]=true;
            }
            if(!v[(now[h]>>1)+16384]){
                now[t++]=(now[h]>>1)+16384;
                nt[tt++]=nt[hh]+1;
                v[(now[h]>>1)+16384]=true;
            }
        }
        if(!v[(now[h]+32767)%32768]){
            now[t++]=(now[h]+32767)%32768;
            nt[tt++]=nt[hh]+1;
            v[(now[h]+32767)%32768]=true;
        }
        h++;
        hh++;
    }
    n=read();
    while(n--){
        a=read();
        write(f[a]);
        putchar(' ');
    }
    return 0;
}