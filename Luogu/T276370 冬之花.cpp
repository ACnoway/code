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
int t,n,x;
int a[10];
int main()
{
    cin>>t;
    bool flag;
    while(t--){
        flag=false;
        cin>>n>>x;
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int i=1;i<=n;++i)
            if(x>0&&a[i]>0||x<0&&a[i]<0||abs(x-0)%abs(a[i])){
                flag=true;
                cout<<"Yes"<<endl;
                break;
            }
        if(flag) continue;
        else cout<<"No"<<endl;
    }
    return 0;
}