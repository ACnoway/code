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
int a[10004];
int l,d,x;
int main()
{
    cin>>l>>d>>x;
    int tmp;
    for(int i=1;i<10004;++i){
        tmp=i;
        while(tmp){
            a[i]+=tmp%10;
            tmp/=10;
        }
    }
    for(int i=l;i<=d;++i){
        if(a[i]==x){
            cout<<i<<endl;
            break;
        }
    }
    for(int i=d;i>=l;--i){
        if(a[i]==x){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}