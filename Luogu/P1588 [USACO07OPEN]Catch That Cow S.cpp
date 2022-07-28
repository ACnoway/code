#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int x,y,ans=0;
        cin>>x>>y;
        int now=x;
        while(now*2<=y) now*=2,ans++;
        int go=y-now;
    }
    return 0;
}