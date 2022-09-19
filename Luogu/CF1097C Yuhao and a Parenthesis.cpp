#include<iostream>
using namespace std;
string a[100005];
int cnt[100005];
bool flag[100005];
int n,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        for(int j=0;j<a[i].size();++j){
            if(a[i][j]=='(') cnt[i]++;
            else cnt[i]--;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(cnt[i]==cnt[j]*(-1)&&!flag[i]&&!flag[j]){
                ans++;
                flag[i]=1;
                flag[j]=1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}