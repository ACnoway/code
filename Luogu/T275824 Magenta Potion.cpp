#include<iostream>
using namespace std;
int n,q;
int a[103];
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>a[i];
    int op,x,y,ls;
    long long ans=1,tmp=1;
    while(q--){
        cin>>op>>x>>y;
        if(op==1) a[x]=y;
        else{
            ans=1;
            ls=1;
            for(int l=1;l<=n;++l){
                for(int r=l;r<=n;++r){
                    tmp=1;
                    for(int i=l;i<=r;++i){
                        tmp*=a[i];
                    }
                    ans=max(ans,tmp);
                }
            }
            if(ans<=(1<<30)) cout<<ans<<endl;
            else cout<<"Too large"<<endl;
        }
    }
    return 0;
}