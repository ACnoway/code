#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int t,n,m;
long double dis(int a,int b,int c,int d){
    return sqrtl((a-c)*(a-c)+(b-d)*(b-d));
}
int main()
{
    int s;
    cin>>s;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cout<<m/2*n+n/2*m-(m/2)*(n/2)<<' ';
        /*long double ans=0;
        int dn=0,dm=0;
        if(n%2==0) dn=1;
        if(m%2==0) dm=1;
        m--;n--;
        int mx=n/2,my=m/2;
        //左上
        cout<<endl;
        for(int i=0;i<=mx;i+=2){
            for(int j=0;j<=my;j+=2){
                cout<<":  "<<i<<' '<<j<<' '<<n-dn<<' '<<m-dm<<endl;
                ans+=dis(i,j,n-dn,m-dm);
            }
        }
        //右上
        for(int i=0;i<=mx;i+=2){
            for(int j=my+1;j<=m-dm;j+=2){
                cout<<":::  "<<i<<' '<<j<<' '<<n-dn<<" 0"<<endl;
                ans+=dis(i,j,n-dn,0);
            }
        }
        //左下
        for(int i=mx+1;i<=n-dn;i+=2){
            for(int j=0;j<=my;j+=2){
                cout<<":::::  "<<i<<' '<<j<<' '<<0<<' '<<m-dm<<endl;
                ans+=dis(i,j,0,m-dm);
            }
        }
        //右下
        for(int i=mx+1;i<=n-dn;i+=2){
            for(int j=my+1;j<=m-dm;j+=2){
                cout<<":::::::::  "<<i<<' '<<j<<endl;
                ans+=dis(i,j,0,0);
            }
        }
        printf("%.9Lf\n",ans);*/
    }
    return 0;
}