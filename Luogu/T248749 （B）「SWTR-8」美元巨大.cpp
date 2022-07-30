#include<iostream>
#include<algorithm>
using namespace std;
int s,t,n,x,y;
int b[25004],ans[65540];
int main()
{
    cin>>s;
    cin>>t;
    if(s==1){
        while(t--){
            cin>>n>>x>>y;
            int ma=0;
            for(int i=0;i<65540;++i) ans[i]=0;
            for(int i=0;i<n;++i){
                cin>>b[i];
                ma=max(ma,b[i]);
                ans[b[i]]=1;
            }
            for(int i=ma;i>=0;--i) cout<<ans[i];
            cout<<endl;
            for(int i=0;i<x;++i) cout<<'^';
            for(int i=0;i<y;++i) cout<<'|';
            cout<<endl;
        }
    }
    else if(s==2){
        while(t--){
            cin>>n>>x>>y;
            for(int i=0;i<n;++i) cin>>b[i];
            if(x&1&&!y){
                cout<<0;
            }
            else{
                cout<<'1';
                for(int i=0;i<b[0];++i) cout<<'0';
            }
            cout<<endl;
            for(int i=0;i<x;++i) cout<<'^';
            for(int i=0;i<y;++i) cout<<'|';
            cout<<endl;
        }
    }
    else if(s==3){
        return 1;
    }
    else if(s==4){
        return 1;
    }
    else{
        return 1;
    }
    return 0;
}