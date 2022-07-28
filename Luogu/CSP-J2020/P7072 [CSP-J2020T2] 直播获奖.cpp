#include<iostream>
#include<cmath>
using namespace std;
int t[605];
int main()
{
    int n,s,p,mi,ma,w;
    cin>>n>>w;
    for(int i=1;i<=n;++i){
        cin>>s;
        mi=min(mi,s);
        ma=max(ma,s);
        t[s]++;
        p=max(1,i*w/100);
        for(int j=ma;j>=mi;--j){
            p-=t[j];
            if(p<=0){
                cout<<j<<' ';
                break;
            }
        }
    }
    return 0;
}