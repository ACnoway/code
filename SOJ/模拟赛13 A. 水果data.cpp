#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;

int main()
{
    freopen("data.txt","w",stdout);
    srand(time(0));
    int n=1000,m=2000;
    char fruit[2]={'H','G'};
    cout<<n<<' '<<m<<endl;
    for(int i=1;i<=n;++i){
        cout<<fruit[rand()%2];
    }
    cout<<endl;
    for(int i=1;i<n;++i){
        cout<<i<<' '<<i+1<<endl;
    }
    for(int i=1;i<=m;++i){
        cout<<rand()%n+1<<' '<<rand()%n+1<<' '<<fruit[rand()%2]<<endl;
    }
    return 0;
}