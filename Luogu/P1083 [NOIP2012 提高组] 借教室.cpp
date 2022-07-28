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
int n,m;
int cl[1000006],d[1000006],s[1000006],t[1000006],diff[1000060];
bool check(int x){
	for(int i=0;i<=(n+50);++i) diff[i]=0;
	for(int i=1;i<=x;++i){
		diff[s[i]]+=d[i];
		diff[t[i]+1]-=d[i];
	}
	for(int i=1;i<=n;++i){
		diff[i]+=diff[i-1];
		if(diff[i]>cl[i]) return 0;
	}
	return 1;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) cl[i]=read();
	for(int i=1;i<=m;++i){
		d[i]=read();
		s[i]=read();
		t[i]=read();
	}
	int l=1,r=m;
	if(check(m)){
		cout<<"0\n";
		return 0;
	}
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	cout<<"-1"<<endl<<l;
	return 0;
}