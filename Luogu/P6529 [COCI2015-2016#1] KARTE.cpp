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
int a[5][15];
int x;
char c;
int main()
{
    while(scanf("%c%d",&c,&x)==2){
        switch (c){
        case 'P':
            a[0][x]++;
            break;
        case 'K':
            a[1][x]++;
            break;
        case 'H':
            a[2][x]++;
            break;
        case 'T':
            a[3][x]++;
            break;
        }
    }
    int ans[4]={0};
    bool flag=true;
    for(int i=0;i<4;++i){
        flag=true;
        for(int j=1;j<=13;++j){
            if(a[i][j]>1){
                flag=false;
                break;
            }
            else if(a[i][j]==0) ans[i]++;
        }
        if(!flag) break;
    }
    if(flag) for(int i=0;i<4;++i) cout<<ans[i]<<' ';
    else cout<<"GRESKA"<<endl;
    return 0;
}