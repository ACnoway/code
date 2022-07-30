#include<iostream>
using namespace std;
const int N=5000;
int n,m;
int p[N];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;++i) p[i]=i;
    int u,v;
    for(int i=0;i<m;++i){
        cin>>u>>v;
        p[find(u)]=find(v);
    }
    
    return 0;
}