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
int t;
int a[10],p[10];
int main()
{
    bool flag=0;
    cin>>t;
    while(t--){
        for(int i=0;i<5;++i) p[i]=i;
        for(int i=0;i<4;++i) cin>>a[i];
        do{
            if(p[0]==4) a[4]=a[p[1]]-1;
            else if(p[1]==4) a[4]=a[p[0]]+1;
            else if(p[2]==4) a[4]=a[p[1]]+1;
            else if(p[3]==4) a[4]=a[p[4]];
            else a[4]=a[p[3]];
            if(a[p[0]]+1==a[p[1]]&&a[p[2]]-1==a[p[1]]&&a[p[3]]==a[p[4]]&&(a[0]>=0&&a[0]<=9)&&(a[1]>=0&&a[1]<=9)&&(a[2]>=0&&a[2]<=9)&&(a[3]>=0&&a[3]<=9)&&(a[4]>=0&&a[4]<=9)){
                flag=1;
                break;
            }
        }while(next_permutation(p,p+5));
        cout<<flag<<endl;
    }
    return 0;
}