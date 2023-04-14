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
int T,k;
int kai(int x){
    int l=0,r=x;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(mid==x/mid) return mid;
        else if(mid>x/mid) r=mid-1;
        else l=mid+1;
    }
    return r;
}
signed main()
{
    T=read();
    while(T--){
        k=read();
        int kaik=kai(k);
        int f=kaik,c=kaik;
        if(f*f!=k) ++c;
        if(f==c){
            if(f&1) printf("1 %lld\n",f);
            else printf("%lld 1\n",f);
        }
        else{
            if(f&1){
                int mid=((c*c-f*f+1)>>1)+f*f;
                if(k<=mid){
                    printf("%lld %lld\n",k-f*f,f+1);
                }
                else{
                    printf("%lld %lld\n",c,f+1-(k-mid));
                }
            }
            else{
                int mid=((c*c-f*f+1)>>1)+f*f;
                if(k<=mid){
                    printf("%lld %lld\n",f+1,k-f*f);
                }
                else{
                    printf("%lld %lld\n",f+1-(k-mid),c);
                }
            }
        }
    }
    return 0;
}