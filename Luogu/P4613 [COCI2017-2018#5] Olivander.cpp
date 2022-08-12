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
int n;
int a[200],b[200];
int main()
{
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;++i){
        if(b[i]<a[i]){
            cout<<"NE"<<endl;
            return 0;
        }
    }
    cout<<"DA"<<endl;
    return 0;
}