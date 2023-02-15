#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
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
const int maxn=1003;
int n,m,k,ha,ta,hi,ti;
int qa[maxn],qi[maxn];
int a[maxn][maxn],xa[maxn][maxn],xi[maxn][maxn],ya[maxn][maxn],yi[maxn][maxn];
int main()
{
    n=read();m=read();k=read();
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) a[i][j]=read();
    for(int i=1;i<=n;++i){
        ha=hi=ta=ti=0;
        for(int j=1;j<=m;++j){
            while(ha<ta&&qa[ha]<=j-k) ha++;
            while(hi<ti&&qi[hi]<=j-k) hi++;
            while(ha<ta&&a[i][qa[ta-1]]<a[i][j]) ta--;
            while(hi<ti&&a[i][qi[ti-1]]>a[i][j]) ti--;
            qa[ta++]=j;
            qi[ti++]=j;
            if(j>=k) xa[i][j-k+1]=a[i][qa[ha]],xi[i][j-k+1]=a[i][qi[hi]];
        }
    }
    for(int i=1;i<=m-k+1;++i){
        ha=ta=0;hi=ti=0;
        for(int j=1;j<=n;++j){
            while(ha<ta&&qa[ha]<=j-k) ha++;
            while(hi<ti&&qi[hi]<=j-k) hi++;
            while(ha<ta&&xa[qa[ta-1]][i]<xa[j][i]) ta--;
            while(hi<ti&&xi[qi[ti-1]][i]>xi[j][i]) ti--;
            qa[ta++]=j;
            qi[ti++]=j;
            if(j>=k) ya[j-k+1][i]=xa[qa[ha]][i],yi[j-k+1][i]=xi[qi[hi]][i];
        }
    }
    
    cout<<"----xa----"<<endl;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m-k+1;++j) cout<<xa[i][j]<<' ';
        cout<<endl;
    }
    cout<<"----xi----"<<endl;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m-k+1;++j) cout<<xi[i][j]<<' ';
        cout<<endl;
    }
    cout<<"----ya----"<<endl;
    for(int i=1;i<=n-k+1;++i){
        for(int j=1;j<=m-k+1;++j) cout<<ya[i][j]<<' ';
        cout<<endl;
    }
    cout<<"----yi----"<<endl;
    for(int i=1;i<=n-k+1;++i){
        for(int j=1;j<=m-k+1;++j) cout<<yi[i][j]<<' ';
        cout<<endl;
    }
    
    int ans=1000000009;
    for(int i=1;i+k-1<=n;++i){
        for(int j=1;j+k-1<=m;++j){
            ans=min(ans,ya[i][j]-yi[i][j]);
            debug(ans);
        }
    }
    write(ans);
    putchar('\n');
    return 0;
}