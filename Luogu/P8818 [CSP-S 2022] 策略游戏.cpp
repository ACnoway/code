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
int n,m,q,l[2],r[2];
int a[100005],b[100005];
int mapi[1000005][20],mapa[1000005][20];
void work()
{
    int i,j;
    for(j=1;1<<j<=n;j++)
        for(i=1;i+(1<<j)-1<=n;i++){
            mapa[i][j]=max(mapa[i][j-1],mapa[i+(1<<j-1)][j-1]);
        }
    for(j=1;1<<j<=m;j++)
        for(i=1;i+(1<<j)-1<=m;i++){
            mapi[i][j]=min(mapi[i][j-1],mapi[i+(1<<j-1)][j-1]);
        }
}
int qmin(int z,int y)
{
    int x=int (log(y-z+1)/log(2));
    return min(mapi[z][x],mapi[y-(1<<x)+1][x]);
}
int qmax(int z,int y)
{
    int x=int (log(y-z+1)/log(2));
    return max(mapa[z][x],mapa[y-(1<<x)+1][x]);
}
int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;++i) cin>>a[i],mapa[i][0]=a[i];
    for(int i=1;i<=m;++i) cin>>b[i],mapi[i][0]=b[i];
    work();
    while(q--){
        for(int i=0;i<2;++i) cin>>l[i]>>r[i];
        cout<<(long long)qmax(l[0],r[0])*(long long)qmin(l[1],r[1])<<endl;
    }
    return 0;
}