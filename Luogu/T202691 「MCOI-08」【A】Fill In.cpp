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
int t,n;
int a[100005],p[100005];
int main()
{
    t=read();
    while(t--){
        n=read();
        bool flag=false;
        for(int i=1;i<=n;++i){
            p[i]=read();
            if(p[i]!=-1) flag=true;
            a[i]=0;
        }
        if(!flag){
            for(int i=1;i<=n;++i) cout<<"1 ";
            cout<<endl;
            continue;
        }
        int now=0;
        for(int i=1;i<=n;++i){
            if(p[i]==-1){
                for(int j=i+1;j<=n;++j){
                    if(p[j]!=-1){
                        a[i]+=p[j]-p[i-1]-j+i;
                        if(a[i]>1000){
                            a[i+1]+=a[i]-1000;
                            a[i]=1000;
                        }
                        p[i]=a[i]+p[i-1];
                        break;
                    }
                }
            }
            else{
                a[i]+=p[i]-p[i-1];
                if(a[i]>1000){
                    a[i+1]+=a[i]-1000;
                    a[i]=1000;
                }
            }
        }
        for(int i=1;i<=n;++i){
            write((a[i]?a[i]:1));
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}