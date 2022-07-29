#include<iostream>
using namespace std;
int n,m;
int p[10004];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;++i) p[i]=i;
    int x,y,z;
    for(int i=0;i<m;++i){
        cin>>z>>x>>y;
        if(z==1){
            p[find(x)]=find(y);
        }
        else{
            if(find(x)==find(y)) cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
    return 0;
}