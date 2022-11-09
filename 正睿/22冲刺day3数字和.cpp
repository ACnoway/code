#include<iostream>
#include<cmath>
using namespace std;
const int N=200005;
int n;
long long a[N],qz[N],hz[N];
int main()
{
    freopen("data.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        qz[i]=max(0ll,qz[i-1])+a[i];
    }
    for(int i=n;i>0;--i){
        hz[i]=max(0ll,hz[i+1])+a[i];
    }
    for(int i=1;i<=n;++i) cout<<qz[i]+hz[i]-a[i]<<' ';
    return 0;
}