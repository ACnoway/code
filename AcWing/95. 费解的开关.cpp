#include <iostream>
#include <cstdio>
using namespace std;
int n;
string a[10],c[10];
int dx[5]={-1,0,1,0,0},dy[5]={0,-1,0,1,0};
void turn(int x,int y){
    for(int i=0;i<5;++i){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<0||xx>=5||yy<0||yy>=5) continue;
        a[xx][yy]^=1;
    }
    return;
}
int main()
{
    cin>>n;
    while(n--){
        for(int i=0;i<5;++i) cin>>a[i];
        int now=10;
        for(int k=0;k<=31;++k){
            for(int i=0;i<5;++i) c[i]=a[i];
            int step=0;
            for(int i=0;i<5;++i){
                if(k>>i&1){
                    step++;
                    turn(0,i);
                }
            }
            for(int i=0;i<4;++i){
                for(int j=0;j<5;++j){
                    if(a[i][j]=='0'){
                        step++;
                        turn(i+1,j);
                    }
                }
            }
            bool flag=false;
            for(int i=0;i<5;++i){
                if(a[4][i]=='0'){
                    flag=true;
                    break;
                }
            }
            if(!flag) now=min(now,step);
            for(int i=0;i<5;++i) a[i]=c[i];
        }
        cout<<(now>6?-1:now)<<endl;
    }
    return 0;
}