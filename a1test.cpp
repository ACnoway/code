#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int main()
{
    freopen("p8818.txt","w",stdout);
    srand(time(0));
    int n=rand()%100+1,m=rand()%100+1,q=rand()%100+1;
    cout<<n<<' '<<m<<' '<<q<<endl;
    for(int i=1;i<=n;++i) cout<<(rand()%2?rand()%100+1:-1*(rand()%100+1))<<' ';
    cout<<endl;
    for(int i=1;i<=m;++i) cout<<(rand()%2?rand()%100+1:-1*(rand()%100+1))<<' ';
    cout<<endl;
    for(int i=0;i<q;++i){
        int l1=rand()%n+1,l2=rand()%m+1;
        int r1=rand()%(n-l1)+l1,r2=rand()%(m-l2)+l2;
        cout<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<endl;
    }
    return 0;
}