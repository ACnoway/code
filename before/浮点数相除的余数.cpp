#include<cstdio>
using namespace std;
int main()
{
	double a,b;
	scanf("%lf%lf",&a,&b);
	int c=a/b; //ȡ�� 
	printf("%g",a-(double)c*b);
	return 0;
} 
