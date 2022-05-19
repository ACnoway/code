#include <iostream>
#include <cstdio>
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
int a[102][102],w[10004][2];
int op[10004],c[102];
int n,m,h=5000,t=5000,cnt;
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            a[i][j]=read();
            c[a[i][j]]++;
            if(a[i][j]!=(m+1-j)&&a[i][j]!=j||c[a[i][j]]>n){
                cout<<"NO"<<endl;
                return 0;
            }
            else if(a[i][j]!=j){
                w[++cnt][0]=i;
                w[cnt][1]=j;
            }
        }
    }
    for(int i=1;i<=m;++i){
        if(c[i]!=n){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(cnt==2){
        if(m==2){
            cout<<"YES"<<endl<<"1"<<endl;
            cout<<"0 "<<w[1][0]<<endl;
        }
        if(w[1][0]==w[2][0]){
            cout<<"YES"<<endl<<"4"<<endl;
            cout<<"1 "<<w[1][1]<<endl;
            cout<<"0 "<<w[2][0]<<endl;
            cout<<"1 "<<w[1][1]<<endl;
            cout<<"0 "<<w[2][0]<<endl;
        }
        else{
            cout<<"YES"<<endl<<"3"<<endl;
            cout<<"0 "<<w[2][0]<<endl;
            cout<<"1 "<<w[1][1]<<endl;
            cout<<"0 "<<w[2][0]<<endl;
        }
    }
    else if(n==2){
        return 0;
    }
    else if(m==2){
        return 0;
    }
    return 0;
}