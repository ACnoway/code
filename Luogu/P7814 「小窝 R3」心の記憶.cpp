#include<iostream>
using namespace std;
string a,b;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        cin>>a;
        if(n==1||n==m||(n==2&&a[0]!=a[1])){
            cout<<"-1"<<endl;
            continue;
        }
        b="";
        int cnt=0;
        for(int i=1;i<n;++i) if(a[i]==a[i-1]) cnt++;
        if(cnt==0){
            b+=a[0];
            for(int i=1;i<=m-n;++i) b+=(a[0]=='1'?'0':'1');
            for(int i=1;i<n;++i) b+=a[i];
        }
        else{
            b+=a[0];
            int p=1;
            for(int i=1;i<n-1&&a[i]!=a[i-1];++i,++p) b+=a[i];
            for(int i=1;i<=m-n;++i) b+=(a[p]=='1'?'0':'1');
            for(int i=p;i<n;++i) b+=a[i];
        }
        cout<<b<<endl;
    }
    return 0;
}