#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
    int n=6,ans=0;
    for(int i=1;i<=n;++i) a[i]=i;
    do{
        for(int i=1;i<=n;++i){
            cout<<a[i]<<' ';
            if((a[i-1]==1&&a[i]==2)||(a[i-1]==2&&a[i]==1)) ans++;
        }
    }while(next_permutation(a+1,a+1+n));
    cout<<endl<<endl<<ans<<endl;
    return 0;
}