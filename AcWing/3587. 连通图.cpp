#include<iostream>
using namespace std;
int n,m;
int p[2000];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    int cnt=0,a,b;
    while(cin>>n>>m){
        for(int i=0;i<=n;++i) p[i]=i;
        cnt=0;
        while(m--){
            cin>>a>>b;
            p[find(a)]=find(b);
        }
        for(int i=1;i<=n;++i){
            if(p[i]==i) cnt++;
        }
        if(cnt>=2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}