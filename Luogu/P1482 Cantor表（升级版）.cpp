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
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int fz1=read(),fm1=read(),fz2=read(),fm2=read();
	int fz=fz1*fz2/gcd(fz1*fz2,fm1*fm2),fm=fm1*fm2/gcd(fz1*fz2,fm1*fm2);
	cout<<fm<<' '<<fz;
	return 0;
}
