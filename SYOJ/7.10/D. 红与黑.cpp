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
int n,m;
double f[2][5003];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        f[i%2][0]=(double)i;
        for(int j=1;j<=m;++j){
            f[i%2][j]=max(0.0,(f[(i-1)%2][j]+1.0)*i/(i+j)+(f[i%2][j-1]-1.0)*j/(i+j));
        }
    }
    f[n%2][m]=floor(f[n%2][m]*1000000.0)/1000000.0;
    printf("%.6lf\n",f[n%2][m]);
    return 0;
}