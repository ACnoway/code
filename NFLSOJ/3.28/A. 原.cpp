#include<iostream>
#include<cstdio>
using namespace std;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}
int T,n,m,b,w;
int ans[210][210];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main()
{
    freopen("nsdd.in","r",stdin);
    freopen("nsdd.out","w",stdout);
    T=read();
    while(T--){
        n=read(); m=read();
        b=read(); w=read();
        n<<=2; m<<=2;
        if(!w){
            for(int i=1;i<=n;++i){
                for(int j=1;j<=m;++j){
                    putchar('.');
                }
                putchar('\n');
            }
            continue;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j) ans[i][j]=-1;
        }
        if(!b){
            ans[1][2]=1;
            for(int i=1;i<=n;++i){
                for(int j=1;j<=m;++j){
                    if(ans[i][j]==1) putchar('W');
                    else putchar('.');
                }
                putchar('\n');
            }
            continue;
        }
        for(int i=2;i<=n;i+=4){
            if(!b) break;
            ans[i-1][2]=1;
            w--;
            ans[i][2]=0;
            b--;
            for(int j=4;j<m;j+=2){
                if(!b) break;
                ans[i][j]=0;
                ans[i][j-1]=1;
                w--; b--;
            }
            if(!b) break;
            ans[i+1][2]=1;
            w--;
            ans[i+2][2]=0;
            b--;
        }
        bool flag=0;
        for(int i=2;i<=n;i+=4){
            for(int j=2;j<m;j+=2){
                if(ans[i][j]==0){
                    for(int k=0;k<4;++k){
                        if(!w){
                            flag=1;
                            break;
                        }
                        int xx=i+dx[k],yy=j+dy[k];
                        if(ans[xx][yy]==-1){
                            ans[xx][yy]=1;
                            w--;
                        }
                    }
                    if(flag) break;
                }
            }
            if(!w){
                flag=1;
                break;
            }
            if(ans[i+2][2]==0){
                for(int k=0;k<4;++k){
                    if(!w){
                        flag=1;
                        break;
                    }
                    int xx=i+2+dx[k],yy=2+dy[k];
                    if(ans[xx][yy]==-1){
                        ans[xx][yy]=1;
                        w--;
                    }
                }
            }
            if(flag) break;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(ans[i][j]==-1) putchar('.');
                else putchar("BW"[ans[i][j]]);
            }
            putchar('\n');
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}