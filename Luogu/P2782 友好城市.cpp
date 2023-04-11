#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int a,b;
}t[200005];
bool cmp(node a,node b){
    return a.a<b.a;
}
int f[200005];
int n,x,y;
int main()
{
    cin>>x>>y>>n;
    for(int i=1;i<=n;++i){
        cin>>t[i].a>>t[i].b;
    }
    sort(t+1,t+n+1,cmp);
    int ans=0;
    for(int i=1;i<=n;++i){
        f[i]=1;
        for(int j=1;j<i;++j){
            if(t[i].b>t[j].b) f[i]=max(f[i],f[j]+1);
        }
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}