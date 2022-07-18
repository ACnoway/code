#include<cstdio>
#include<cmath> 
int main()
{
	float m,t,s;
	scanf("%f%f%f",&m,&t,&s);
	int a=m-ceil(s/t);
	if (a<0){
		printf("0");
	}
	if (a>=0){
		printf("%d",a);
	}
	
	return 0;
} 
