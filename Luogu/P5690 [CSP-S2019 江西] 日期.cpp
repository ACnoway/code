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
int m,d;
//             1  2  3  4  5  6  7  8  9 10 11 12
int da[23]={31,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    scanf("%d-%d",&m,&d);
    int ans=0;
    if(m==0) ans++;
    else if(m>12){
        ans++;
        if(d>max(da[m%10],max(da[m%10+10],da[m/10]))||d==0) ans++;
    }
    else{
        if(d>da[m]||d==0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}