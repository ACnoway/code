#include<cstdio>
#include<cmath> 
using namespace std;
int main()
{
	int n,a;
	float x,y;
	scanf("%d%f%f",&n,&x,&y);
	a=n-ceil(y/x);
	printf("%d",a);
	return 0;
} 
