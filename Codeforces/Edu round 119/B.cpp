#include <iostream>
#include <cstdio>
#include <cmath>
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
int k[10];
int t,h,w,big;
int x0xiao,x0da,xhxiao,xhda;
int y0xiao,y0da,ywxiao,ywda;
int main()
{
	t=read();
	for(int T=1;T<=t;++T){
		w=read();h=read();
		//输入位于x轴上的点                      //
		k[0]=read();						  //      |
		x0xiao=read();						  //     h|----(w,h)
		for(int i=1;i<k[0];++i) x0da=read();  //      |    |
		//位于h地方的点                         //-------------->x
		k[1]=read();                          //      |    w
		xhxiao=read();                        //      |
		for(int i=1;i<k[1];++i) xhda=read();  //      |
		//输入位于x轴上的点                     
		k[2]=read();						  
		y0xiao=read();						  
		for(int i=1;i<k[2];++i) y0da=read();  
		//位于h地方的点                         
		k[3]=read();                          
		ywxiao=read();                        
		for(int i=1;i<k[3];++i) ywda=read();
		int x0=x0da-x0xiao,xh=xhda-xhxiao,y0=y0da-y0xiao,yw=ywda-ywxiao;
		int sx0=x0*max(h,max(y0da,ywda)),sxh=xh*max(h,min(y0xiao,ywxiao)),sy0=y0*max(w,max(x0da,xhda)),
			syw=yw*max(w,min(x0xiao,xhxiao));
		int ans=max(sx0,max(sy0,max(sxh,syw)));
		write(ans);
		putchar('\n');
	}
	return 0;
}