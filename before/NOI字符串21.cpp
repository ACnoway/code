#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string a,b;
char st[101][101];
int main()
{
	char temp; 
	//���嵽��������Ϊ���嵽ѭ���ڻ���Ϊ�ֲ�����,
	//while�����޷��жϣ�����ʾ�޴˱��� 
	int ti=0; //�жϵڼ������ʼ�֮���ѭ������ 
	do{
		scanf("%s",&st[ti++]);
		temp=getchar(); //�洢ÿ������֮����ַ� 
	}while(temp!='\n'/*��Ϊ���з������洢*/);
	ti--; //����ѭ���ж�ӵ�һ�� 
	cin>>a>>b;
	for(int i=0;i<=ti;i++){
		string temp1=st[i]; //��string���ͷ���Ƚ� 
		if(temp1==a){ //���������Ϊ����a 
			cout<<b; //ֱ�����Ҫ�滻�ĵ��� 
		}
		else{
			printf("%s",st[i]);
			//�������ԭ�ȵĵ��� 
		}
		if(i!=ti) cout<<" "; //�ж��Ƿ�����ո� 
	}
	return 0;
}
