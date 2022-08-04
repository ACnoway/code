#include<iostream>
using namespace std;
int n,k;
int a[1005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    cin>>k;
    for(int i=1<<(k-1);i<=(1<<k)-1&&i<=n;++i) cout<<a[i]<<' ';
    if(n<(1<<(k-1))) cout<<"EMPTY"<<endl;
    return 0;
}