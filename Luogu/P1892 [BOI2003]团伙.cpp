#include<iostream>
using namespace std;
int n,m;
int p[2003];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<=2*n;++i) p[i]=i;
    char c;
    int a,b;
    while(m--){
        cin>>c>>a>>b;
        if(c=='E'){
            p[find(a+n)]=find(b);
            p[find(b+n)]=find(a);
        }
        else p[find(a)]=find(b);
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        if(p[i]==i) ans++;
    }
    cout<<ans<<endl;
    return 0;
}