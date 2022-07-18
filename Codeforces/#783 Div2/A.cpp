#include<cstdio>
#include<iostream>
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
    putchar(x%10-'0');
}
int main(){
	int t;
	t=read();
	int n,m;
	while(t--){
		n=read();
        m=read();
		n-=1;m-=1;
		if(m<n)swap(n,m);
		if((m-n)&1){
			if(n==0&&m!=1){
                write(-1);
                putchar('\n');
            }
			else{write(2*m-1);putchar('\n');}
		}
		else{
			if(n==0&&m!=0){
                write(-1);
                putchar('\n');
            }
			else{write(2*m);putchar('\n');}
		}
	}
	return 0;
}
