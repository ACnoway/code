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
int n,m,x,y;
string s;
int a[1003][1003],f[1003][1003];
int main()
{
    cin>>n>>m>>y>>x;
    cin>>s;
    int xn=x,yn=y;
    f[xn][yn]=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            a[i][j]+=(1-f[i][j]);
        }
    }
    for(int i=0;i<m-1;++i){
        switch (s[i])
        {
        case 'N':
            xn++;
            break;
        case 'S':
            xn--;
            break;
        case 'W':
            yn--;
            break;
        case 'E':
            yn++;
            break;
        }
        f[xn][yn]=i+2;
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                a[j][k]+=(i+2-f[j][k]);
            }
        }
    }
    for(int i=n;i>0;--i){
        for(int j=1;j<=n;++j) cout<<a[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}