#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
inline int read(){
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int N=1010;
long long t,id,n,m,c,f,st,en,ac,af;
long long fh[N][N],fl[N][N],fc[N][N],ff[N][N];
char a[N][N];
const int P=998244353;
int main()
{
    t=read();id=read();
    if(id==1){
        while(t--) cout<<"0 0"<<endl;
        return 0;
    }
    else{
        while(t--){
            n=read();m=read();c=read();f=read();
            //多测不清空，AC见祖宗
            ac=0;af=0;
            for(int i=0;i<=n+1;++i)
                for(int j=0;j<=m+1;++j){
                    fc[i][j]=ff[i][j]=0;
                    fh[i][j]=fl[i][j]=-1;
                    a[i][j]=0;
                }
            for(int i=1;i<=n;++i) cin>>(a[i]+1);
            
            for(int i=1;i<=n;++i)
                for(int j=m;j>0;--j)
                    if(a[i][j]=='0') fh[i][j]=fh[i][j+1]+1;
                    
            for(int i=1;i<=m;++i)
                for(int j=n;j>0;--j)
                    if(a[j][i]=='0'){
                        fl[j][i]=fl[j+1][i]+1;
                        fc[j][i]=(fc[j+1][i]%P+fh[j][i]%P)%P;
                        ff[j][i]=(ff[j+1][i]%P+(fh[j][i]*fl[j][i])%P)%P;
                    }
            
            for(int i=1;i+2<=n;++i){
                for(int j=1;j+1<=m;++j){
                    if(a[i+1][j]=='1'||a[i][j]=='1'||!fh[i][j]) continue;
                    ac=(ac%P+(fh[i][j]*fc[i+2][j])%P)%P;
                }
            }
            for(int i=1;i+3<=n;++i){
                for(int j=1;j+1<=m;++j){
                    if(a[i+1][j]=='1'||a[i][j]=='1'||!fh[i][j]) continue;
                    af=(af%P+(fh[i][j]*ff[i+2][j])%P)%P;
                }
            }
            write(ac*c);putchar(' ');
            write(af*f);putchar('\n');
        }
    }
    return 0;
}
