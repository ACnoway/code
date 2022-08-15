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
int n,w,h,x;
int main()
{
    cin>>n>>w>>h;
    for(int i=0;i<n;++i){
        cin>>x;
        if(x>sqrt(w*w+h*h)) cout<<"NE"<<endl;
        else cout<<"DA"<<endl;
    }
    return 0;
}