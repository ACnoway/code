#include<iostream>
using namespace std;
int n,m;
int p[400010];
int get(int x,int y){
    return x*n+y;
}
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<400010;++i) p[i]=i;
    int res=0;
    for(int i=1;i<=m;++i){
        int x,y;
        char d;
        cin>>x>>y>>d;
        x--;
        y--;
        int a=get(x,y);
        int b;
        if(d=='D') b=get(x+1,y);
        else b=get(x,y+1);
        int pa=find(a),pb=find(b);
        if(pa==pb){
            res=i;
            break;
        }
        p[pa]=pb;
    }
    if(!res) cout<<"draw"<<endl;
    else cout<<res<<endl;
    return 0;
}