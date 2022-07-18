#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("f1.in","w",stdout);
    srand(time(0));
    int t=1,n=200000;
    cout<<t<<endl;
    char c[2]={'+','-'};
    for(int j=1;j<=t;++j){
        cout<<n<<endl;
        for(int i=1;i<=n;++i) cout<<c[rand()%2];
        cout<<endl;
    }
    return 0;
}