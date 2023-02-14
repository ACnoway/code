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
const int maxn=100005;
int n,d,mx,may,mix=1000006,miy=1000006,ha,hb,ta,tb;
int qa[maxn],qb[maxn];
class node{
    public:
        int x,y;
        bool operator <(const node &p)const{
            return x<p.x;
        }
}a[maxn];
bool check(int k){
    bool flag=0;
    ha=hb=0;ta=tb=0;
    for(int i=1;i<=n;++i){
        while(ha<ta&&a[qa[ha]].x<a[i].x-k) ha++;
        while(hb<tb&&a[qb[hb]].x<a[i].x-k) hb++;
        while(ha<ta&&a[qa[ta-1]].y<a[i].y) ta--;
        while(hb<tb&&a[qb[tb-1]].y>a[i].y) tb--;
        qa[ta++]=i;
        qb[tb++]=i;
        if(a[i].x-mix+1>=k){
            debug(a[qa[ha]].y);debug(a[qb[hb]].y);
            if(a[qa[ha]].y-a[qb[hb]].y>=d){
                flag=1;
                break;
            }
        }
    }
    return flag;
}
int main()
{
    n=read();d=read();
    for(int i=1;i<=n;++i){
        a[i].x=read(),a[i].y=read();
        mx=max(mx,a[i].x),mix=min(mix,a[i].x);
        may=max(may,a[i].y),miy=min(miy,a[i].y);
    }
    if(may-miy<d){
        write(-1);
        putchar('\n');
        return 0;
    }
    sort(a+1,a+1+n);
    int ans=1000006;
    int l=1,r=mx-mix+1,mid;
    while(l<r){
        mid=(l+r)>>1;
        debug(l);debug(r);
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    write(r);
    putchar('\n');
    return 0;
}