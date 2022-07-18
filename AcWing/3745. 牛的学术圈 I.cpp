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
int t[100005],cnt[100005];
int n,l,big;
int main()
{
    n=read();
    l=read();
    for(int i=0;i<n;++i){
        int temp=read();
        t[temp]++;
        cnt[temp]++;
        big=max(big,temp);
    }
    for(int i=big-1;i>=0;--i) t[i]+=t[i+1];
    for(int i=big+1;i>0;--i){
        if(t[i]+min(cnt[i-1],l)>=i){
            write(i);
            putchar('\n');
            return 0;
        }
    }
    write(l?1:0);
    putchar('\n');
    return 0;
}