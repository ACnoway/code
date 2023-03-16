#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<climits>
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
const int N=500005;
int t,n;
struct node{
    int v,p;
    bool operator <(const node x)const{
        return v<x.v;
    }
}a[N],b[N];
int tong[N];
int main()
{
    t=read();
    while(t--){
        n=read();
        for(int i=1;i<=n;++i){
            a[i].v=read();
            a[i].p=i;
            b[i].v=read();
            b[i].p=i;
            tong[i]=0;
        }
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        int x=n,ma,cha=INT_MAX;
        //for(int i=1;i<=n;++i) debug(a[i].v),debug(b[i].v);
        if(a[n].v<b[n].v){
            for(int i=1;i<=n;++i){
                tong[a[i].p]=1;
                ma=lower_bound(b+1,b+n+1,a[i])-b;
                int j;
                for(;x&&tong[b[x].p];--x);
                if(ma<=x){
                    cha=min(cha,abs(a[i].v-b[x].v));
                }
                else{
                    for(int k=max(1,ma-2);k<=min(ma+1,n);++k){
                        if(b[k].p!=a[i].p) cha=min(cha,abs(a[i].v-b[k].v));
                    }
                }
            }
        }
        else{
            for(int i=1;i<=n;++i){
                tong[b[i].p]=1;
                ma=lower_bound(a+1,a+n+1,b[i])-a;
                int j;
                for(;x&&tong[a[x].p];--x);
                if(ma<=x){
                    cha=min(cha,abs(b[i].v-a[x].v));
                }
                else{
                    for(int k=max(1,ma-2);k<=min(ma+1,n);++k){
                        if(a[k].p!=b[i].p) cha=min(cha,abs(b[i].v-a[k].v));
                    }
                }
            }
        }
        printf("%d\n",cha);
    }
    return 0;
}