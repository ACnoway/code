#include <iostream>
using namespace std;
int a[7],w[7]={0,1,2,3,5,10,20};
int t[2003];
int main()
{
    for(int i=1;i<=6;++i) cin>>a[i];
    t[0]=1;
    for(int i=1;i<=6;++i){
        for(int j=1;j<=a[i];++j){
            for(int k=1000;k>=0;--k){
                if(t[k]) t[k+w[i]]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=1000;++i) ans+=t[i];
    cout<<ans<<endl;
    return 0;
}