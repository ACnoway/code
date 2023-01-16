#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int a[3]={-1,0,1};
int b[10000007];
int Rand(int n)
{
    return rand() % n ;
}
int main()
{
    freopen("p8945.in","w",stdout);
    srand(time(0));
    int n=rand()%10000000+1,k=rand()%n+1;
    cout<<n<<' '<<k<<endl;
    for(int i=1;i<=k;++i){
        b[i]=0;
    }
    for(int i=k+1;i<=n;++i) b[i]=a[rand()%3];
    random_shuffle(b+1, b+1+n, pointer_to_unary_function<int, int>(Rand));
    for(int i=1;i<=n;++i) cout<<b[i]<<' ';
    return 0;
}