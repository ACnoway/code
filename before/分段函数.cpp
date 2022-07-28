#include<cstdio>
using namespace std;
int main()
{
	float n;
	scanf("%f",&n);
	if(0<=n&&n<5) printf("%.3f",-n+2.5);
	else if(5<=n&&n<10) printf("%.3f",2.0-1.5*(n-3.0)*(n-3.0)); 
	else printf("%.3f",n/2.0-1.5);
	return 0;
}


