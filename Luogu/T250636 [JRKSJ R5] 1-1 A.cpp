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
int n,c1,c2;
int a[1000006],f[1000006];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]==1) c1++;
        else c2++;
    }
    int mi,ma;
    if(c1>c2){
        while(c2){
            ma=c1/c2;
            c2--;
            for(int i=0;i<ma;++i) cout<<1<<' ';
            cout<<-1<<' ';
            c1-=ma;
        }
    }
    else{
        while(c1){
            ma=c2/c1;
            c1--;
            for(int i=0;i<ma;++i) cout<<-1<<' ';
            cout<<1<<' ';
            c2-=ma;
        }
    }
    return 0;
}