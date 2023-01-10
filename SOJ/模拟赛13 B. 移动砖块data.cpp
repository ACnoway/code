#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;

int main()
{
    freopen("dataB.txt","w",stdout);
    srand(time(0));
    int n=100;
    cout<<n<<' '<<rand()%1000<<' '<<rand()%1000<<' '<<rand()%1000<<endl;
    for(int i=1;i<n;++i){
        cout<<i<<' '<<i+1<<endl;
    }
    return 0;
}