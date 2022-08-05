#include<iostream>
using namespace std;
const int N=1003;
int a[N],c[N];
int n;
int main()
{
    cin>>n;
    int ans=0;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(a[i]>a[j]) c[a[j]]++;
        }
    }
    for(int i=0;i<n;++i) cout<<c[i]<<' ',ans+=c[i];
    cout<<endl<<ans<<endl;
    return 0;
}