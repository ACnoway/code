#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string a,b;
char st[101][101];
int main()
{
	char temp; 
	//定义到外面是因为定义到循环内会视为局部变量,
	//while条件无法判断，会显示无此变量 
	int ti=0; //判断第几个单词及之后的循环次数 
	do{
		scanf("%s",&st[ti++]);
		temp=getchar(); //存储每个单词之后的字符 
	}while(temp!='\n'/*若为换行符结束存储*/);
	ti--; //减掉循环中多加的一次 
	cin>>a>>b;
	for(int i=0;i<=ti;i++){
		string temp1=st[i]; //用string类型方便比较 
		if(temp1==a){ //若这个单词为单词a 
			cout<<b; //直接输出要替换的单词 
		}
		else{
			printf("%s",st[i]);
			//否则输出原先的单词 
		}
		if(i!=ti) cout<<" "; //判断是否输出空格 
	}
	return 0;
}
