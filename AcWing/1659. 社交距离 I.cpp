#include <iostream>
#include <cstdio>
#include <cmath>
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
int n,cnt,ans,at,bt;
int a[100005];
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        char c=0;
        while(c!='0'&&c!='1') c=getchar();
        if(c=='1'){
            a[++cnt]=i;
            //cout<<i<<endl;
        }
    }
    if(!cnt){
        cout<<n-1;
        return 0;
    }
    else{
        int mi=100005;
        for(int i=1;i<cnt;++i){
            mi=min(mi,a[i+1]-a[i]);
        }
        int ma=max((a[1]-1)/2,(n-a[cnt])/2);
        for(int i=1;i<cnt;++i)
            ma=max(ma,(a[i+1]-a[i])/3);
        int b1=a[1]-1,b2=n-a[cnt];
        if(b1<b2) swap(b1,b2);
        for(int i=1;i<cnt;++i){
            int temp=(a[i+1]-a[i])/2;
            if(temp>=b1){
                b2=b1;
                b1=temp;
            }
            else if(temp>b2){
                b2=temp;
            }
        }
        write(min(mi,max(ma,b2)));
        putchar('\n');

    }
    return 0;
}