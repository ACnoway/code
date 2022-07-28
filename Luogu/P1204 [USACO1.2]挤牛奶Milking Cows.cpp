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
int t[1000006];
int main()
{
	int n,lmin=1000006,rmax=0;
	n=read();
	for(int i=0;i<n;++i){
		int l,r;
		l=read();r=read();
		lmin=min(lmin,l);
		rmax=max(rmax,r);
		t[l]+=1;
		t[r]-=1;
	}
	for(int i=1;i<=rmax;++i) t[i]+=t[i-1];
	int mh=0,th=0,mn=0,tn=0;
	for(int i=lmin;i<rmax;++i){
		if(t[i-1]==0&&t[i]){
			th=1;
			if(mh) mn=max(mn,tn);
			tn=0;
		}
		else if(t[i-1]&&t[i]==0){
			tn=1;
			mh=max(mh,th);
			th=0;
		}
		else if(t[i]==0) tn++;
		else if(t[i]) th++;
	}
	mh=max(mh,th);
	mn=max(mn,tn);
	write(mh);putchar(' ');write(mn);
	return 0;
}