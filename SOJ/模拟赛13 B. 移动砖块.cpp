#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int c[102];
int n,x,y,z,a,b,sa,sb,ans,need;
bool fm,fl;
int main()
{
    cin>>n>>x>>y>>z;
    for(int i=1;i<=n;++i){
        cin>>a>>b;
        sa+=a;sb+=b;
        c[i]=a-b;
        if(c[i]>0) fm=1;
        else if(c[i]<0) fl=1;
    }
    for(int t=1;t<=n;++t){
        if(fm&&fl){
        for(int i=1;i<=n;++i){
            if(c[i]>0){
                for(int j=1;j<n;++j){
                    if(c[i]==0||(i-j>0&&c[i-j]>0)||i-j<0) break;
                    need=min(c[i],-c[i-j]);
                    c[i]-=need;c[i-j]+=need;
                    ans+=min(need*x+need*y,need*z*j);
                }
                for(int j=1;j<n;++j){
                    if(c[i]==0||(i+j<=n&&c[i+j]>0)||i+j>n) break;
                    if(i+j<=n&&c[i+j]<0){
                        need=min(c[i],-c[i+j]);
                        c[i]-=need;c[i+j]+=need;
                        ans+=min(need*x+need*y,need*z*j);
                    }
                }
            }
        }
        fm=fl=0;
        for(int i=1;i<=n;++i){
            if(c[i]>0) fm=1;
            else if(c[i]<0) fl=1;
        }
        }
        else{
            if(sa>sb) ans+=(sa-sb)*y;
            else if(sa<sb) ans+=(sb-sa)*x;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}