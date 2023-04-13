#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cout<<i<<':'<<endl;
        for(int j=0;j<n;++j){
            for(int k=0;k<n;++k){
                if((j+k)%n==i) cout<<j<<' '<<k<<endl;
            }
        }
    }
    return 0;
}