#include<bits/stdc++.h>
using namespace std;
int w,m,n,kx,ky,x=0,y=1;
int main()
{
    scanf("%d%d%d",&w,&m,&n);
    if(n>m) swap(n,m);
    for(register int i=1;i<=m;i++)    //枚举从1到m所有数的坐标
    {
    	if(y%2==1)    //正方向
    	{
    		x++;
    		if(x>w) x=w,y++;
		}
		else    //反方向
		{
			x--;
			if(x<1) x=1,y++;
		}
		if(i==n) kx=x,ky=y;    //记录n的坐标
	}
	printf("%d",abs(kx-x)+abs(ky-y));
    return 0;
}
