#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,c;
long long ans;
int a[200001];
int main()
{
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    n--;
    for(int i=n;i>=1&&a[i]>=c;i--){
        ans+=upper_bound(a,a+n,a[i]-c)-lower_bound(a,a+n,a[i]-c);
    }
    cout<<ans;
    return 0; 
}