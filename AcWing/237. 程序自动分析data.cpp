#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=1000;
    freopen("237.txt","w",stdout);
    cout<<1<<endl<<n/2<<endl;
    for(int i=1;i<=n;i+=2){
        cout<<i<<' '<<i+1<<' '<<rand()%2<<endl;
    }
    return 0;
}