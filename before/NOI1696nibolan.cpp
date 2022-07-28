#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
double nibolan(){
	char a[100001];
	scanf("%s",&a);
	switch(a[0]){
		default:{
			return atof(a);
			break;
		}
		case '+':{
			return nibolan()+nibolan();
			break;
		}
		case '-':{
			return nibolan()-nibolan();
			break;
		}
		case '*':{
			return nibolan()*nibolan();
			break;
		}
		case '/':{
			return nibolan()/nibolan();
			break;
		}
	}
}
int main()
{
	printf("%lf",nibolan());
	return 0;
}

