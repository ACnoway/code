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
struct node
{
    int a,b;
    bool operator <(const node &x)const{
        return (double)a/(double)b<(double)x.a/(double)x.b;
    }
}a[100000];
int gcd(int a,int b){
    if(!b) return a;
    return gcd(b,a%b);
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            if(gcd(i,j)==1){
                a[++cnt].a=j;
                a[cnt].b=i;
                // cout<<j<<'/'<<i<<'\n';
            }
        }
    }
    sort(a+1,a+1+cnt);
    for(int i=1;i<=cnt;++i){
        cout<<a[i].a<<'/'<<a[i].b<<endl;
    }
    cout.flush();
    return 0;
}