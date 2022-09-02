#include <iostream>
using namespace std;
int b[1000006],e[1000006];
int main()
{
    int n,m,cb=0,ce=0,d;
    char p;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>d>>p;
        for(int j=1;j<=d;++j){
            ++cb;
            if(p=='L') b[cb]=b[cb-1]-1;
            else b[cb]=b[cb-1]+1;
        }
    }
    for(int i=1;i<=m;++i){
        cin>>d>>p;
        for(int j=1;j<=d;++j){
            ++ce;
            if(p=='L') e[ce]=e[ce-1]-1;
            else e[ce]=e[ce-1]+1;
        }
    }
    if(ce>cb){
        for(int i=cb+1;i<=ce;++i) b[i]=b[i-1];
    }
    if(ce<cb){
        for(int i=ce+1;i<=cb;++i) e[i]=e[i-1];
    }
    cb=max(cb,ce);
    int ans=0;
    for(int i=1;i<=cb;++i){
        if(b[i]==e[i]&&b[i-1]!=e[i-1]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}