#include<iostream>
using namespace std;
int t,s;
int a[1003][1003];
const int INF=2147483647;
int xx[4]={1,0,-1,0},yy[4]={0,1,0,-1};
int main()
{
    cin>>t;
    int r,d,cnt,x,y;
    bool flag;
    for(int tt=1;tt<=t;++tt){
        cin>>s;
        r=INF;d=0;
        for(int i=0;i<s;++i){
            for(int j=0;j<s;++j) cin>>a[i][j];
        }
        for(int i=0;i<s;++i){
            for(int j=0;j<s;++j){
                cnt=0;
                x=i;y=j;
                while(1){
                    flag=0;
                    for(int k=0;k<4;++k){
                        if(x+xx[k]<0||y+yy[k]<0||x+xx[k]>=s||y+yy[k]>=s) continue;
                        if(a[x+xx[k]][y+yy[k]]==a[x][y]+1){
                            x+=xx[k];y+=yy[k];
                            flag=1;
                            break;
                        }
                    }
                    if(flag) cnt++;
                    else break;
                }
                if(cnt>d){
                    d=cnt;
                    r=a[i][j];
                }
                else if(cnt==d) r=min(r,a[i][j]);
            }
        }
        cout<<"Case #"<<tt<<": "<<r<<' '<<d+1<<endl;
    }
    return 0;
}