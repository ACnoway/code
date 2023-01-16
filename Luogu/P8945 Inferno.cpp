/*#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
const int maxn=10000007;
int n,k,cnt,ans=-maxn;
int a[maxn],t[maxn];
struct node{
    int v,p;
}fa[maxn],fb[maxn];
int get(int x){
    int l=fa[x].p,r=fb[x].p;
    int cc=t[r]-t[l-1];
    return a[r]-a[l-1]+(cc>k?k-cc+k:cc);
}
int main()
{
    freopen("p8945.in","r",stdin);
    freopen("p8945.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<=n;++i){
        fa[i].p=fb[i].p=i;
        fa[i].v=maxn;
        fb[i].v=-maxn;
    }
    for(int i=1;i<=n;++i){
        cin>>a[i];
        t[i]=t[i-1];
        if(a[i]==0) cnt++,t[i]++;
        a[i]+=a[i-1];
        fa[i].v=fb[i].v=a[i];
        if(fa[i].v>fa[i-1].v){
            fa[i].v=fa[i-1].v;
            fa[i].p=fa[i-1].p;
        }
    }
    for(int i=n;i;--i){
        if(fb[i].v<fb[i+1].v){
            fb[i].v=fb[i+1].v;
            fb[i].p=fb[i+1].p;
        }
    }
    cout<<"v=";
    for(int i=1;i<=n;++i) cout<<fa[i].v<<' ';
    cout<<endl<<"p=";
    for(int i=1;i<=n;++i) cout<<fa[i].p<<' ';
    cout<<endl;
    cout<<"v=";
    for(int i=1;i<=n;++i) cout<<fb[i].v<<' ';
    cout<<endl<<"p=";
    for(int i=1;i<=n;++i) cout<<fb[i].p<<' ';
    cout<<endl;
    for(int i=1;i<=n;++i){
        ans=max(ans,get(i));
    }
    cout<<ans<<endl;
    return 0;
}
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
const int maxn=10000007;
int n,k,cnt,ans=-maxn;
int a[maxn],t[maxn];
struct node{
    int v,p;
}fa[maxn],fb[maxn];
int get(int x){
    int l=fa[x].p,r=fb[x].p;
    int cc=t[r]-t[l-1];
    return a[r]-a[l-1]+(cc>k?k-cc+k:cc);
}
int get1(int x){
    int l=fa[x].p,r=fb[x-1].p;
    if(l>r) return -maxn;
    int cc=t[r]-t[l-1];
    return a[r]-a[l-1]+(cc>k?k-cc+k:cc);
}
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
int main()
{
    freopen("p8945.in","r",stdin);
    freopen("p8945.out","w",stdout);
    n=read();k=read();
    for(int i=0;i<=n;++i){
        fa[i].p=fb[i].p=i;
        fa[i].v=maxn;
        fb[i].v=-maxn;
    }
    for(int i=1;i<=n;++i){
        a[i]=read();
        if(a[i]==0) cnt++;
        t[i]=cnt;
        a[i]+=a[i-1];
        if(fa[cnt+1].v>a[i]){
            fa[cnt+1].v=a[i];
            fa[cnt+1].p=i;
        }
        if(fb[cnt].v<a[i]){
            fb[cnt].v=a[i];
            fb[cnt].p=i;
        }
    }
    for(int i=1;i<=cnt+1;++i){
        if(fa[i].v>fa[i-1].v){
            fa[i].v=fa[i-1].v;
            fa[i].p=fa[i-1].p;
        }
    }
    for(int i=cnt;i>=0;--i){
        if(fb[i].v<fb[i+1].v){
            fb[i].v=fb[i+1].v;
            fb[i].p=fb[i+1].p;
        }
    }
    cout<<"v=";
    for(int i=1;i<=cnt;++i) cout<<fa[i].v<<' ';
    cout<<endl<<"p=";
    for(int i=1;i<=cnt;++i) cout<<fa[i].p<<' ';
    cout<<endl;
    cout<<"v=";
    for(int i=1;i<=cnt;++i) cout<<fb[i].v<<' ';
    cout<<endl<<"p=";
    for(int i=1;i<=cnt;++i) cout<<fb[i].p<<' ';
    cout<<endl;
    for(int i=1;i<=cnt;++i){
        ans=max(ans,get(i));
        ans=max(ans,get1(i));
    }
    write(ans);putchar('\n');
    return 0;
}*/
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
const int maxn=10000007;
int n,k,cnt,ans;
int a[maxn];
struct node{
    int v,p;
}fa[maxn],fb[maxn];
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
int get(int x){
    int l=fa[x].p,r=fb[x].p;
    int cc=r-l+1;
    return fb[r].v-fa[l].v+(cc>k?k-cc+k:cc);
}
int main()
{
    freopen("p8945.in","r",stdin);
    freopen("p8945.out","w",stdout);
    n=read();k=read();
    for(int i=0;i<=n+1;++i){
        fa[i].p=fb[i].p=i;
        fa[i].v=maxn;
        fb[i].v=-maxn;
    }
    for(int i=1;i<=n;++i){
        a[i]=read();
        if(a[i]==0) cnt++;
        a[i]+=a[i-1];
        fa[cnt+1].v=min(fa[cnt+1].v,a[i]);
        fb[cnt].v=max(fb[cnt].v,a[i]);
    }
    for(int i=1;i<=cnt+1;++i){
        if(fa[i].v>fa[i-1].v){
            fa[i].v=fa[i-1].v;
            fa[i].p=fa[i-1].p;
        }
    }
    for(int i=cnt;i>=0;--i){
        if(fb[i].v<fb[i+1].v){
            fb[i].v=fb[i+1].v;
            fb[i].p=fb[i+1].p;
        }
    }
    for(int i=1;i<=cnt;++i){
        ans=max(ans,get(i));
    }
    write(ans);putchar('\n');
    return 0;
}