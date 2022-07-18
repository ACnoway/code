#include<cstdio>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if (b>d)
	{
		
		e=c-1-a;
		f=d+60-b;
		printf("%d %d",e,f); 
	} 
	if (d>=b)
	{
		
		e=c-a;
		f=d-b;
		printf("%d %d",e,f);
	}
	return 0;
}
