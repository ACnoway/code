#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
const int N=200005;
int n,m;
int a[N];
template<class T,const int sz>
class SegTree{
    private:
        inline int lson(int x){return x<<1;}
        inline int rson(int x){return x<<1|1;}
        double sine[sz<<2],cosi[sz<<2];
        int lt[sz<<2];
        inline void pushup(int x){
            sine[x]=sine[lson(x)]+sine[rson(x)];
            cosi[x]=cosi[lson(x)]+cosi[rson(x)];
        }
        inline void update(int x,double sinx,double cosx){
            double sina=sine[x],cosa=cosi[x];
            sine[x]=sina*cosx+cosa*sinx;
            cosi[x]=cosa*cosx-sina*sinx;
        }
        inline void pushdown(int x){
            if(lt[x]){
                double sinx=sin(lt[x]),cosx=cos(lt[x]);
                update(lson(x),sinx,cosx);
                update(rson(x),sinx,cosx);
                lt[lson(x)]+=lt[x];
                lt[rson(x)]+=lt[x];
                lt[x]=0;
            }
        }
    public:
        void build(int x,int l,int r){
            if(l==r){
                sine[x]=sin(a[l]);
                cosi[x]=cos(a[l]);
                return;
            }
            int mid=(l+r)>>1;
            build(lson(x),l,mid);
            build(rson(x),mid+1,r);
            pushup(x);
        }
        void modify(int x,int l,int r,int L,int R,int k){
            if(L<=l&&r<=R){
                update(x,sin(k),cos(k));
                lt[x]+=k;
                return;
            }
            pushdown(x);
            int mid=(l+r)>>1;
            if(L<=mid) modify(lson(x),l,mid,L,R,k);
            if(R>mid) modify(rson(x),mid+1,r,L,R,k);
            pushup(x);
        }
        double query(int x,int l,int r,int L,int R){
            if(L<=l&&r<=R) return sine[x];
            double s=0;
            int mid=(l+r)>>1;
            pushdown(x);
            if(L<=mid) s+=query(lson(x),l,mid,L,R);
            if(R>mid) s+=query(rson(x),mid+1,r,L,R);
            return s;
        }
};
SegTree<int,N> T;
signed main()
{
    int op,l,r,k;
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    T.build(1,1,n);
    m=read();
    while(m--){
        op=read();
        l=read(); r=read();
        if(op==1){
            k=read();
            T.modify(1,1,n,l,r,k);
        }
        else printf("%.1lf\n",T.query(1,1,n,l,r));
    }
    return 0;
}