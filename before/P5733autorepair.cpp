#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
string a;
int main()
{
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(islower(a[i])) printf("%c",toupper(a[i]));
		else printf("%c",a[i]);
	}
	return 0;
}

