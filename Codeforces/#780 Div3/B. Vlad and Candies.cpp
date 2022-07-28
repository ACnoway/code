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
int main()
{
    int t=read();
    while(t--){
        int n=read();
        int a=0,b=0;
        while(n--){
            int temp=read();
            if(temp>=a){
                b=a;
                a=temp;
            }
            else if(temp>=b){
                b=temp;
            }
        }
        if(a-b>1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}