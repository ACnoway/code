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
int sh[1000006],kc[1000006];
int n,m,t1=0,t2=0,ans;
bool lx=false;
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		int s=read(),t=read();
		for(int j=1;j<=t;++j){
			t1+=1;
			sh[t1]=s+sh[t1-1];
		}
	}
	for(int i=1;i<=m;++i){
		int s=read(),t=read();
		for(int j=1;j<=t;++j){
			t2+=1;
			kc[t2]=s+kc[t2-1];
		}
	}
	if(sh[1]>kc[1]) lx=true;
	else lx=false;
	for(int i=2;i<=t1;++i){
		//cout<<"t="<<i<<" sh:"<<sh[i]<<" kc:"<<kc[i]<<endl;
		if((sh[i]>kc[i]&&!lx)||(sh[i]<kc[i]&&lx)){
			ans++;
			lx=!lx;
		}
	}
	write(ans);
	return 0;
}