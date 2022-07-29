#include<iostream>
#include<unordered_map>
using namespace std;
int n,m,k;
int p[20004];
unordered_map<string,int> ls;
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;++i) p[i]=i;
    string s;
    for(int i=1;i<=n;++i){
        cin>>s;
        ls[s]=i;
    }
    string a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        p[find(ls[a])]=find(ls[b]);
    }
    cin>>k;
    for(int i=0;i<k;++i){
        cin>>a>>b;
        if(find(ls[a])==find(ls[b])) cout<<"Yes."<<endl;
        else cout<<"No."<<endl;
    }
    return 0;
}