#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ull unsigned long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
const ull P=131;
const ull M=1e9+7;
ull a[1000006],b[1000006],p[1000006];
int n,cnt,i;
char t[2000006];
string s;
ull get1(int l,int r){
    return (a[r]+M-(a[l]*p[r-l])%M)%M;
}
ull get2(int l,int r){
    return (b[r]+M-(b[l]*p[r-l])%M)%M;
}
bool check(int x){
    debug(((get1(n-x,n)*p[n-x])%M+a[n-x])%M);
    debug((b[n]*p[x])%M);
    return ((get1(n-x,n)*p[n-x])%M+a[n-x])%M==(b[n]*p[x])%M;
}
int main()
{
    cin>>n>>t+1;
    p[0]=1;
    for(int i=n;i;--i){
        a[n-i+1]=((a[n-i]*P)%M+(t[i]-'a'+1))%M;
    }
    for(int i=n+1;i<=2*n;++i){
        b[i-n]=((b[i-n-1]*P)%M+(t[i]-'a'+1))%M;
        p[i-n]=(p[i-n-1]*P)%M;
    }
    for(int i=1;i<=n;++i){
        s+=t[i];
        if(check(i)){
            cout<<s;
            for(int j=n;j>i;--j) putchar(t[j]);
            cout<<endl<<i;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}