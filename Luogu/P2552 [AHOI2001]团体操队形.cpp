#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int k;
    int n,way,pai,r,m;
    cin>>k;
    while(k--){
        cin>>n>>way>>pai>>r>>m;
        if(way==1){
            int h=m/r,l=m%r;
            if(m%r==0) l=r;
            else h+=1;
            if(pai==1) cout<<h<<' '<<l<<' ';
            else cout<<l<<' '<<h<<' ';
        }
        else{
            int h=m/r*2,l=0;
            if(m%r==0){
                if(pai==1) cout<<h<<' '<<r-(r&1)<<' ';
                else cout<<r-(r&1)<<' '<<h<<' ';
                continue;
            }
            else h++;
            m%=r;
            int now=((r+1)>>1);
            if(m%now==0){
                if(pai==1) cout<<h<<' '<<r-!(r&1)<<' ';
                else cout<<r-!(r&1)<<' '<<h<<' ';
                continue;
            }
            if(m<=now){
                if(pai==1)
                    cout<<h<<' '<<m*2-1<<' ';
                else cout<<m*2-1<<' '<<h<<' ';
                continue;
            }
            else{
                m-=now;
                if(pai==1)
                    cout<<h+1<<' '<<m*2<<' ';
                else cout<<m*2<<' '<<h+1<<' ';
            }
        }
    }
    return 0;
}