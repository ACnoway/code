#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
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
const int maxn=1000006;
int n,k,head,tail;
int a[maxn],q[maxn];
int main()
{
    n=read();k=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i){
        while(head<tail&&q[head]<=i-k) head++;
        while(head<tail&&a[q[tail-1]]>a[i]) tail--;
        q[tail++]=i;
        if(i>=k) write(a[q[head]]),putchar(' ');
    }
    putchar('\n');
    head=tail=0;
    for(int i=1;i<=n;++i){
        while(head<tail&&q[head]<=i-k) head++;
        while(head<tail&&a[q[tail-1]]<a[i]) tail--;
        q[tail++]=i;
        if(i>=k) write(a[q[head]]),putchar(' ');
    }
    return 0;
}