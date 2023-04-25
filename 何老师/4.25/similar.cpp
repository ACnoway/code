#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
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
int n,q;
struct node{
    int ch[2];
    string v;
    node(){ch[0]=ch[1]=0;v="";}
}s[102],t[102];
void build(int x,int len){
    if(len==1){
        return;
    }
    s[x].ch[0]=x<<1;
    for(int i=0;i<(len>>1);++i) s[x<<1].v+=s[x].v[i];
    s[x].ch[1]=x<<1|1;
    for(int i=(len>>1);i<len;++i) s[x<<1|1].v+=s[x].v[i];
    
    t[x].ch[0]=x<<1;
    for(int i=0;i<(len>>1);++i) t[x<<1].v+=t[x].v[i];
    t[x].ch[1]=x<<1|1;
    for(int i=(len>>1);i<len;++i) t[x<<1|1].v+=t[x].v[i];
    build(x<<1,len>>1);
    build(x<<1|1,len>>1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    n=1<<n;
    cin>>s[1].v;
    cin>>t[1].v;
    build(1,n);
    return 0;
}