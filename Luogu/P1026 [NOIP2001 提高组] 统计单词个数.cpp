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
int n,k,s;
int w[205][205],f[205][45];
string a,b,wo[10];
int have(int x,int end){
    for(int i=0;i<s;++i){
        int p=a.find(wo[i],x);
        if(p==x) return 1;
    }
    return 0;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>b;
        a+=b;
    }
    n=a.size();
    cin>>s;
    for(int i=0;i<s;++i) cin>>wo[i];
    for(int j=n-1;j>=0;--j){
        for(int i=j;i>=0;--i) w[i][j]=w[i+1][j]+have(i,j);
    }
    f[0][1]=w[0][0];
    for(int i=1;i<=k;++i) f[i][i]=f[i-1][i-1]+w[i][i];
    for(int i=0;i<n;++i) f[i][1]=w[0][i];
    for(int i=0;i<n;++i){
        for(int j=2;j<=k&&j<=i;++j){
            for(int r=j-1;r<i;++r){
                if(f[i][j]<f[r][j-1]+w[r+1][i]) f[i][j]=f[r][j-1]+w[r+1][i];
            }
        }
    }
    cout<<f[n-1][k];
    return 0;
}