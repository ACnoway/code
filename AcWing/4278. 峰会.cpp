#include<iostream>
using namespace std;
int n,m,k,l;
int p[300][300];
int x[300];
bool v[300];
int main()
{
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        p[a][b]=1;
        p[b][a]=1;
    }
    cin>>k;
    bool flag;
    for(int i=1;i<=k;++i){
        cin>>l;
        for(int j=0;j<=n;++j) v[j]=0;
        for(int j=0;j<l;++j) cin>>x[j],v[x[j]]=1;
        flag=1;
        for(int j=0;j<l;++j){
            for(int k=j+1;k<l;++k){
                if(!p[x[j]][x[k]]){
                    flag=0;
                    break;
                }
            }
        }
        if(!flag){
            cout<<"Area "<<i<<" needs help."<<endl;
            continue;
        }
        flag=1;
        for(int j=1;j<=n;++j){
            if(v[j]) {flag=0;continue;}
            flag=1;
            for(int k=0;k<l;++k){
                if(!p[j][x[k]]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                cout<<"Area "<<i<<" may invite more people, such as "<<j<<"."<<endl;
                break;
            }
            flag=0;
        }
        if(!flag) cout<<"Area "<<i<<" is OK."<<endl;
    }
    return 0;
}