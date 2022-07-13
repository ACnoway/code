#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;//要转化的字符串长度
	char s[n];
	cin>>s;//字符串
	puts("#include<stdio.h>");
	printf("int a[]={");
	int*a=(int*)s;
	for(int i=0;i<=(n-1)/4;i++)printf("%d,",a[i]);
	putchar('\b');
	printf("};\n");
	puts("int main(){puts((const char*)a);}");
	return 0;
}