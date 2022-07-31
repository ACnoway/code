#include<iostream>
using namespace std;
int n,m,cnt;
int a[100005],ans[100005];
int main()
{
    cin>>n>>m;
    int x;
    for(int i=0;i<m;++i){
        cin>>x;
        if(a[x]==0) cnt++;
        a[x]++;
        if(cnt==n){
            ans[i]=1;
            for(int j=1;j<=n;++j){
                if(a[j]==1) cnt--;
                a[j]--;
            }
        }
    }
    for(int i=0;i<m;++i) cout<<ans[i];
    return 0;
}