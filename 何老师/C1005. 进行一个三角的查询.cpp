#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
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
int n,q;
class Pos{
    public:
        int x,y,d,id;
        Pos(int _x=0,int _y=0,int _d=0,int _id=0):
            x(_x),y(_y),d(_d),id(_id){}
}a[maxn<<1];
inline int lowbit(int x){
    return x&(-x);
}
class Tree{
    private:
        int c[maxn<<1];
    public:
        void add(int x,int k){
            for(;x<=2000000;x+=lowbit(x)) c[x]+=k;
        }
        int ask(int x){
            int sum=0;
            for(;x;x-=lowbit(x)) sum+=c[x];
            return sum;
        }
        void clear(){
            memset(c,0,sizeof(c));
        }
}c;
bool cmpY(Pos x,Pos y){
    if(x.y!=y.y) return x.y<y.y;
    return x.id>y.id;
}
bool cmpB(Pos x,Pos y){
    int b1=x.x+x.y+x.d;
    int b2=y.x+y.y+y.d;
    if(b1!=b2) return b1<b2;
    return x.id<y.id;
}
int ans[maxn];
int main()
{
    n=read();
    q=read();
    int x,y,d;
    for(int i=1;i<=n;++i){
        x=read();y=read();
        a[i]=Pos(x,y,0,0);
    }
    for(int i=1;i<=q;++i){
        x=read();y=read();
        d=read();
        a[i+n]=Pos(x,y,d,i);
    }
    sort(a+1,a+1+n+q,cmpB);
    for(int i=1;i<=n+q;++i){
        if(a[i].id==0) c.add(a[i].x,1);
        else{
            ans[a[i].id]=ans[a[i].id]+c.ask(a[i].x+a[i].d)-c.ask(a[i].x-1);
        }
    }
    c.clear();
    sort(a+1,a+1+n+q,cmpY);
    for(int i=1;i<=n+q;++i){
        if(a[i].id==0) c.add(a[i].x,1);
        else{
            ans[a[i].id]=ans[a[i].id]-c.ask(a[i].x+a[i].d)+c.ask(a[i].x-1);
        }
    }
    for(int i=1;i<=q;++i){
        write(ans[i]);
        putchar('\n');
    }
    return 0;
}