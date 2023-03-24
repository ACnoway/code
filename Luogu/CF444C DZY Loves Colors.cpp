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
const int N=100005;
int n,m,len,cnt;
int bl[N],g[N][2],lt[N],glt[N],sum[N],v[N],color[N];
void san(int l,int r,int x){
    //暴力重构l和r的零散部分
    int p=bl[l];
    //整块下放标记
    if(lt[p]){
        //如果颜色一样
        for(int i=g[p][0];i<l;++i) color[i]=lt[p];
        for(int i=r+1;i<=g[p][1];++i) color[i]=lt[p];
        for(int i=l;i<=r;++i){
            sum[p]+=abs(lt[p]-x);
            v[i]+=abs(lt[p]-x);
            color[i]=x;
        }
    }
    else{
        //如果不一样
        for(int i=l;i<=r;++i){
            sum[p]+=abs(color[i]-x);
            v[i]+=abs(color[i]-x);
            color[i]=x;
        }
        
    }
    lt[p]=0;
}
void gai(int l,int r,int x){
    int p;
    san(l,min(r,g[bl[l]][1]),x);
    if(bl[l]!=bl[r]){
        san(g[bl[r]][0],r,x);
    }
    //整块修改
    p=bl[l];
    for(int i=p+1;i<bl[r];++i){
        if(lt[i]){
            //如果整块是同一颜色就可以整块修改
            glt[i]+=abs(lt[i]-x);
            sum[i]+=abs(lt[i]-x)*(g[i][1]-g[i][0]+1);
            lt[i]=x;
        }
        else{
            //不是的话就暴力修改
            for(int j=g[i][0];j<=g[i][1];++j){
                sum[i]+=abs(color[j]-x);
                v[j]+=abs(color[j]-x);
                color[j]=x;
            }
            lt[i]=x;
        }
    }
}
int query(int l,int r){
    int ans=0,p=bl[l];
    for(int i=l;i<=min(g[p][1],r);++i){
        ans+=v[i]+glt[p];
    }
    if(bl[l]!=bl[r]){
        p=bl[r];
        for(int i=g[p][0];i<=r;++i){
            ans+=v[i]+glt[p];
        }
    }
    for(int i=bl[l]+1;i<bl[r];++i){
        ans+=sum[i];
    }
    return ans;
}
signed main()
{
    n=read();
    m=read();
    len=sqrt(n);
    cnt=n/len;
    if(len*cnt<n) cnt++;
    for(int i=1;i<=n;++i) color[i]=i;
    for(int i=1;i<=cnt;++i){
        g[i][0]=(i-1)*len+1;
        g[i][1]=min(n,i*len);
        for(int j=g[i][0];j<=g[i][1];++j) bl[j]=i;
    }
    int op,l,r,x;
    while(m--){
        op=read();
        l=read(); r=read();
        if(op==1){
            x=read();
            gai(l,r,x);
        }
        else{
            printf("%lld\n",query(l,r));
        }
    }
    return 0;
}