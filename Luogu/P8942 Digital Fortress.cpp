#include<iostream>
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
inline long long readll(){
    long long x=0,f=1;
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
inline void write(long long x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int main()
{
    int t,n,cnt;
    long long m;
    t=read();
    while(t--){
        n=read();
        m=readll();
        cnt=0;
        while(m){
            cnt++;
            m>>=1;
        }
        if(n>cnt){
            putchar('N');putchar('o');
            putchar('\n');
            continue;
        }
        putchar('Y');putchar('e');putchar('s');
        putchar('\n');
        for(int i=0;i<n;++i){
            write(1ll<<i);
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}