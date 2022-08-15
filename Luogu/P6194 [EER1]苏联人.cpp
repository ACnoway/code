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
int f[10][10];
char a[10][10];
int main()
{
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j) cin>>a[i][j];
    }
    int ii,jj;
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            if(a[i][j]=='R'){
                f[i][j]=1;
                ii=i-1;jj=j;
                while(ii>=0&&jj>=0&&a[ii][jj]=='.') f[ii--][jj]=1;
                ii=i+1;jj=j;
                while(ii<8&&jj<8&&a[ii][jj]=='.') f[ii++][jj]=1;
                ii=i;jj=j-1;
                while(ii>=0&&jj>=0&&a[ii][jj]=='.') f[ii][jj--]=1;
                ii=i;jj=j+1;
                while(ii<8&&jj<8&&a[ii][jj]=='.') f[ii][jj++]=1;
            }
            else if(a[i][j]=='B'){
                f[i][j]=1;
                ii=i-1;jj=j-1;
                while(ii>=0&&jj>=0&&a[ii][jj]=='.') f[ii--][jj--]=1;
                ii=i+1;jj=j+1;
                while(ii<8&&jj<8&&a[ii][jj]=='.') f[ii++][jj++]=1;
                ii=i+1;jj=j-1;
                while(ii<8&&jj>=0&&a[ii][jj]=='.') f[ii++][jj--]=1;
                ii=i-1;jj=j+1;
                while(ii>=0&&jj<8&&a[ii][jj]=='.') f[ii--][jj++]=1;
            }
        }
    }
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j) cout<<!f[i][j];
        cout<<endl;
    }
    return 0;
}