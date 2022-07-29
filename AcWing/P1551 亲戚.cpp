#include<iostream>
using namespace std;
int n,m,p;
int fa[5003];
int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}
int main()
{
    cin>>n>>m>>p;
    for(int i=0;i<=n;++i) fa[i]=i;
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        fa[find(a)]=find(b);
    }
    for(int i=0;i<p;++i){
        cin>>a>>b;
        if(find(a)==find(b)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}