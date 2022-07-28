#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int a,b;
	char ys;
	scanf("%d%c%d",&a,&ys,&b);
	switch(ys){
		case '+':{
			cout<<a+b;
			break;
		}
		case '-':{
			cout<<a-b;
			break;
		}
		case '*':{
			cout<<a*b;
			break;
		}
		case '/':{
			cout<<a/b;
			break;
		}
		case '%':{
			cout<<a%b;
			break;
		}
	}
	return 0;
}

