#include<cstdio>
#include<iostream> 
#include<cmath>
using namespace std;
inline float dis(int x1,int x2,int y1,int y2){
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
int main()
{
	float x1,y1,x2,y2,x3,y3,m,n,e,p,s;
	scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);
	m=dis(x1,x2,y1,y2);
	n=dis(x2,x3,y2,y3);
	e=dis(x3,x1,y3,y1);
	p=(m+n+e)/2;
	s=sqrt(p*(p-m)*(p-n)*(p-e));
	printf("%0.2f",s);
	return 0;
}
