#include<cstdio>
int main()
{
	int a,b,c,d,e;
	scanf("%d.%d",&a,&e);
	b=a/100;
	c=a/10%10;
	d=a%10;
	printf("%d.%d%d%d",e,d,c,b);
	return 0;
}
