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
const int maxn=502,maxm=100010;
struct node{
    int nxt,to;
}e[maxm];
int idx,head[maxn];
int n1,n2,m;
int match[maxn];
bool st[maxn];
inline void add(int u,int v){
    e[++idx].to=v;
    e[idx].nxt=head[u];
    head[u]=idx;
}
bool find(int x){
    for(int i=head[x];i;i=e[i].nxt){
        int j=e[i].to;
        if(!st[j]){
            st[j]=1;
            if(match[j]==0||find(match[j])){
                match[j]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    n1=read();n2=read();
    m=read();
    while(m--){
        int a,b;
        a=read();
        b=read();
        add(a,b);
    }
    int ans=0;
    for(int i=1;i<=n1;++i){
        for(int j=0;j<maxn;++j) st[j]=0;
        if(find(i)) ans++;
    }
    write(ans);
    putchar('\n');
    return 0;
}