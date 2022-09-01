#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1003],f[1003];
bool v[1003];
int n;
int main()
{
    cin>>n;
    int ans=0;
    bool flag;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
        int j;
        flag=true;
        for(int j=0;j<=n;++j) v[j]=0;
        while(j){
            if(v[j]||f[j]==2){
                flag=false;
                break;
            }
            if(f[j]==1){
                flag=true;
                break;
            }
            v[j]=1;
            j=a[j];
        }
        if(flag){
            f[i]=1;
            ans++;
        }
        else f[i]=2;
    }
    cout<<ans<<endl;
    return 0;
}