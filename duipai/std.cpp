#include<iostream>
#include<cmath>
#define int long long
using namespace std;
int t,n,k,l;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n,k=ceil(sqrt(n)),l=n-(k-1)*(k-1);
        if(k&1)cout<<min(k+k-l,k)<<' '<<min(l,k)<<endl;
        else cout<<min(l,k)<<' '<<min(k+k-l,k)<<endl;
    }
}