#include<cstdio>
#include<cmath>
int main()
{
	float xa,ya,xb,yb;
	scanf("%f%f%f%f",&xa,&ya,&xb,&yb);
	printf("%0.3f",sqrt(pow(xa-xb,2)+pow(ya-yb,2)));
	return 0;
}
