#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=500005;
int t,n,x,y,xc,yc,ax,ay;
bool flag;
int xs[N],ys[N];
vector<int> xx[N],yy[N];
inline int read(){
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x;
}
int main()
{
    t=read();
    while(t--){
        n=read();
        for(int i=0;i<=n;++i){
            xs[i]=ys[i]=0;
            xx[i].clear();
            yy[i].clear();
        }
        flag=false;
        xc=yc=0;
        for(int i=1;i<=n;++i){
            x=read();y=read();
            xs[x]++;
            ys[y]++;
            xx[x].push_back(y);
            yy[y].push_back(x);
        }
        for(int i=1;i<=n;++i) xs[i]+=xs[i-1],ys[i]+=ys[i-1];
        for(int i=1;i<=n;++i){
            if(xs[i]==(n>>1)||ys[i]==(n>>1)){
                flag=true;
                break;
            }
            if(xs[i]>(n>>1)&&ys[i]>(n>>1)) break;
        }
        if(flag){
            putchar('2');
            putchar('\n');
            continue;
        }
        ax=3;ay=3;
        for(int i=2;i<=n;++i){
            if(xs[i-1]<(n>>1)&&xs[i]>(n>>1)){
                sort(xx[i].begin(),xx[i].end());
                y=xx[i][xs[i]-(n>>1)];
                for(int j=i+1;j<=n;++j){
                    for(int k=0;k<xx[j].size();++k){
                        if(xx[j][k]>=y){
                            ax++;
                            break;
                        }
                    }
                    if(ax==4) break;
                }
                break;
            }
        }
        for(int i=2;i<=n;++i){
            if(ys[i-1]<(n>>1)&&ys[i]>(n>>1)){
                sort(yy[i].begin(),yy[i].end());
                x=yy[i][ys[i]-(n>>1)];
                for(int j=i+1;j<=n;++j){
                    for(int k=0;k<yy[j].size();++k){
                        if(yy[j][k]>=x){
                            ay++;
                            break;
                        }
                    }
                    if(ay==4) break;
                }
                break;
            }
        }
        putchar(min(ax,ay)+48);
        putchar('\n');
    }
    return 0;
}