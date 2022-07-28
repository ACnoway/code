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
int c[5],m[5];
int main()
{
    for(int i=1;i<=3;++i){
        c[i]=read();
        m[i]=read();
    }
    int cnt=100;
    while(1){
        if(cnt){
            m[2]+=m[1];
            m[1]=0;
            if(m[2]>c[2]){
                m[1]+=m[2]-c[2];
                m[2]=c[2];
            }
            cnt--;
        }
        if(cnt){
            m[3]+=m[2];
            m[2]=0;
            if(m[3]>c[3]){
                m[2]+=m[3]-c[3];
                m[3]=c[3];
            }
            cnt--;
        }
        if(cnt){
            m[1]+=m[3];
            m[3]=0;
            if(m[1]>c[1]){
                m[3]+=m[1]-c[1];
                m[1]=c[1];
            }
            cnt--;
        }
    }
    for(int i=1;i<=3;++i){
        write(m[i]);
        putchar('\n');
    }
    return 0;
}