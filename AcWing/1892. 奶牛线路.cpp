#include <iostream>
using namespace std;
int n,a,b;
int main()
{
    cin>>a>>b>>n;
    int m,nn,w,flag,ans=2000;
    for(int i=1;i<=n;++i){
        cin>>m>>nn;
        flag=0;
        for(int j=1;j<=nn;++j){
            cin>>w;
            if(w==a&&flag==0) flag++;
            if(w==b&&flag==1) flag++;
        }
        if(flag==2) ans=min(ans,m);
    }
    cout<<(ans==2000?-1:ans);
    return 0;
}