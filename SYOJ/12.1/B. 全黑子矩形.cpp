#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
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
const int N=3003;
int n,m;
int a[N][N],f[N][N];
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            a[i][j]=read();
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+(!a[i][j]);
        }
    }
    int ans=0;
    for(int sx=1;sx<=n;++sx)
        for(int sy=1;sy<=n;++sy)
            for(int ex=sx;ex<=n;++ex)
                for(int ey=sy;ey<=m;++ey)
                    if(!(f[ex][ey]-f[ex][sy-1]-f[sx-1][ey]+f[sx-1][sy-1])) ++ans,cout<<sx<<' '<<sy<<' '<<ex<<' '<<ey<<endl;
    printf("%d\n",ans);
    return 0;
}
