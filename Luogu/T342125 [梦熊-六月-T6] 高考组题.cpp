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
struct node{
    double v;
    int p;
    bool operator <(const node &x)const{
        if(v==x.v) return p<x.p;
        return v>x.v;
    }
}a[200];
int n,k,sum,x;
int main()
{
    n=read();
    k=read();
    for(int i=0;i<n;++i){
        sum=0;
        for(int j=0;j<k;++j){
            x=read();
            sum+=x;
        }
        a[i].v=(double)sum/(double)k;
        a[i].p=i+1;
    }
    sort(a,a+n);
    cout<<a[0].p<<endl<<a[1].p<<endl;
    return 0;
}