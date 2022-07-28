//打表过了
#include <iostream>
#include <cstdio>
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
void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int t,n;
int main()
{
    t=read();
    while(t--){
        n=read();
        int ans=0;
        for(int i=1;i<=n;++i){
            int temp=i;
            ans++;
            while(temp){
                int k=temp%10;
                temp/=10;
                if(k==7){
                    ans--;
                    break;
                }
            }
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}