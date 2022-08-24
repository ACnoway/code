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
inline __int128_t read(){
    __int128_t x=0,f=1;
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
inline void write(__int128_t x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
__int128_t ans=1;
string n;
int k;
int t[15][15];
int a[50];
int main()
{
    cin>>n;
    cin>>k;
    int x,y;
    for(int i=0;i<k;++i){
        cin>>x>>y;
        t[x][y]=1;
    }
    for(int k=1;k<10;++k){
        for(int i=0;i<10;++i){
            for(int j=1;j<10;++j){
                if(t[i][k]&&t[k][j]) t[i][j]=1;
            }
        }
    }
    for(int i=0;i<10;++i){
        t[i][i]=1;
        for(int j=0;j<10;++j){
            if(t[i][j]) a[i]++;
        }
    }
    for(int i=0;i<n.size();++i){
        ans*=a[(n[i]-'0')];
    }
    write(ans);
    return 0;
}