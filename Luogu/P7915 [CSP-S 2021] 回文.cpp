//TODO 双端队列，https://www.luogu.com.cn/blog/101868/solution-p7915
#include <iostream>
#include <cstdio>
#include <deque>
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
const int N=1000006;
int T,n;
int t[N];
char now[N],ans[N];
struct node
{
    int s[N];
    int l,r;
}a,b;
int main()
{
    T=read();
    while(T--){
        n=read();
        a.l=1;a.r=1;
        b.l=1;b.r=1;
        for(int i=1;i<=(n<<1);++i) t[i]=read();
        int f=t[1],p=2;
        while(t[p]!=f) a.s[a.r++]=t[p++];
        p++;
        while(p<=n) b.s[a.r++]=t[p++];
        while(b.r>b.l){
            
        }
    }
    return 0;
}