#include<iostream>
using namespace std;
inline long long read(){
    long long x=0;
    char c=getchar();
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x;
}
inline int rint(){
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x;
}
inline void write(long long x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int main()
{
    int t;
    t=rint();
    long long l,r;
    while(t--){
        l=read();r=read();
        write(((r-l+1)>>1)+(l&1&&r&1));
        putchar('\n');
    }
    return 0;
}