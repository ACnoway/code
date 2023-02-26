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
const int maxn=200005;
int n,m,x,y,cnt;
int a[maxn],rd[maxn];
int id,to[maxn],nxt[maxn],head[maxn];
int h,t,q[maxn];
inline void add(int u,int v){
    to[++id]=v;
    nxt[id]=head[u];
    head[u]=id;
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=m;++i){
        x=read();
        y=read();
        add(x,y);
        rd[y]++;
    }
    for(int i=1;i<=n;++i){
        if(rd[i]==0){
            q[++t]=i;
        }
    }
    if(t==0||t>1){
        cout<<"No"<<endl;
        return 0;
    }
    int p;
    while(h<t){
        p=q[++h];
        a[p]=h;
        cnt=0;
        for(int i=head[p];i;i=nxt[i]){
            y=to[i];
            if(rd[y]==1&&!cnt){
                cnt++;
                rd[y]--;
                q[++t]=y;
            }
            else if(rd[y]==1&&cnt){
                cout<<"No"<<endl;
                return 0;
            }
            else rd[y]--;
        }
    }
    bool flag=1;
    for(int i=1;i<=n;++i){
        if(rd[i]){
            flag=0;
            break;
        }
    }
    if(!flag){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<=n;++i) write(a[i]),putchar(' ');
    return 0;
}