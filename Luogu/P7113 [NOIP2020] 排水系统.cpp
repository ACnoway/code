#include <iostream>
#include <cstdio>
#define int __int128_t
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
int gcd(int a,int b){
    return b ? gcd(b,a%b):a;
}
const int N=10000005;
struct fs{
    int fz,fm;
    fs(int _fz=0,int _fm=1):fz(_fz),fm(_fm){}
    void operator=(const fs &x){
        fz=x.fz;
        fm=x.fm;
        if(fz==0){
            fm=0;
            return;
        }
        int d=gcd(fz,fm);
        fz/=d;
        fm/=d;
    }
}v[N];
fs operator+(const fs &a,const fs &b){
    return fs(a.fz*b.fm+b.fz*a.fm,a.fm*b.fm);
}
fs operator/(const fs &a,const int &b){
    return fs(a.fz,a.fm*b);
}
int n,m;
/*
in入度，out出度
h_i表示第i个点的第一条边的编号
e_i表示第i条边的终点，ne_i表示第i条边的下一条边
fz_i表示第i个点的污水量的分子，fm_i表示第i个点的污水量的分母
*/
int in[N],out[N],h[N],e[N],ne[N],idx;
int q[N],hh=0,tt=-1;
//加边，维护出度入度
void adde(int a,int b){
    in[b]++;
    e[idx]=b; ne[idx]=h[a]; h[a]=idx++;
}
void work(){
    while(hh<=tt){
        int t=q[hh++];
        /*cout<<"t: ";
        write(t);
        cout<<endl;*/
        for(signed i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            /*cout<<"------------------"<<endl;
            write(v[t].fz);
            putchar(' ');
            write(v[t].fm);
            putchar('\n');
            cout<<"------------------"<<endl;*/
            v[j]=v[j]+(v[t]/out[t]);
            if(--in[j]==0){
                q[++tt]=j;
            }
        }
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("P7113_7.in","r",stdin);
    #endif
    //freopen("p7113.txt","w",stdout);
    idx=1;
    for(int i=0;i<N;++i) h[i]=-1;

    n=read(); m=read();

    int cnt,to;
    for(int i=1;i<=n;++i){
        cnt=read();
        out[i]=cnt;
        for(int j=1;j<=cnt;++j){
            to=read();
            adde(i,to);
        }
    }
    for(int i=1;i<=m;++i){
        q[++tt]=i;
        v[i]=v[i]+fs(1,1);
    }
    work();
    for(int i=1;i<=n;++i){
        if(!out[i]){
            int d=gcd(v[i].fz,v[i].fm);
            write(v[i].fz/d);
            putchar(' ');
            write(v[i].fm/d);
            putchar('\n');
        }
    }
    return 0;
}