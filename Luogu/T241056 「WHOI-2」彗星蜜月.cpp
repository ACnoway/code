#include <iostream>
#include <cmath>
#define int unsigned long long
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
signed main()
{
    int t,n;
    t=read();
    while (t--) {
        n=read();
        int k=0,nn=n;
        while(nn){
            nn/=10;
            ++k;
        }
        k=pow(10,k);
        for(int i=n+1;i<k;++i){
            int temp=i;
            nn=0;
            while(temp){
                nn=(nn<<3)+(nn<<1)+temp%10;
                temp/=10;
            }
            if(nn>n) break;
        }
        cout<<--k<<endl;
    }
    return 0;
}