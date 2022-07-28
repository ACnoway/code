#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[200],f1[200],f2[200];
int k,n,ans;
int main()
{
    cin>>k;
    while(k--){
        a[0]=0;
        ans=0;
        for(int i=0;i<200;++i){
            f1[i]=0;
            f2[i]=0;
        }
        cin>>n;
        for(int i=1;i<=n;++i) cin>>a[i];
        //最长上升子序列
        for(int i=1;i<=n;++i){
            f1[i]=1;
            for(int j=1;j<=i;++j){
                if(a[j]<a[i]) f1[i]=max(f1[i],f1[j]+1);
            }
        }
        //最长下降子序列
        for(int i=1;i<=n;++i){
            f2[i]=1;
            for(int j=1;j<=i;++j){
                if(a[j]>a[i]) f2[i]=max(f2[i],f2[j]+1);
            }
        }
        for(int i=1;i<=n;++i) ans=max(ans,max(f1[i],f2[i]));
        cout<<ans<<endl;
    }
    return 0;
}