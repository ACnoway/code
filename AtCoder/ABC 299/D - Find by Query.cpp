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
int n;
int main()
{
    cin>>n;
    int l=1,r=n,mid,x,ans=0;
    while(l<r){
        mid=(l+r)>>1;
        cout<<"? "<<mid<<endl;
        cin>>x;
        if(l>=r-1){
            ans=l;
            break;
        }
        if(x==0) l=mid;
        else r=mid;
    }
    cout<<"! "<<ans<<endl;
    return 0;
}