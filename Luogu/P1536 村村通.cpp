#include<iostream>
using namespace std;
int p[1000006];
int n,m;
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    int a,b,ans;
    while(cin>>n>>m){
        for(int i=0;i<=n;++i) p[i]=i;
        for(int i=0;i<m;++i){
            cin>>a>>b;
            p[find(a)]=find(b);
        }
        ans=0;
        for(int i=1;i<=n;++i){
            if(find(i)==i) ans++;
        }
        cout<<ans-1<<endl;
    }
    return 0;
}
