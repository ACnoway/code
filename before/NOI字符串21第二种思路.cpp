#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string s,a,b;
int main()
{
	getline(cin,s);
	cin>>a>>b;
	a=' '+a+' '; b=' '+b+' '; s=' '+s+' ';
	//���ַ������˼ӿո񣬷�ֹ�����ж���ĸ�Ƿ���ֶ����ǵ����Ƿ���֡�
	//��ֻ���ַ�����ӿո������ֵ���aǰ����ĸ���ɱ��滻����� 
	int l=a.size();
	while(s.find(a)!=-1/*�ж��ַ���s�����Ƿ��е���a*/){
		s.replace(s.find(a),l,b); //�滻����aΪ����b
	}
	s.erase(s.begin(),s.begin()+1);s.erase(s.end()--,s.end());
	//ɾ��ǰ��ͺ���Ŀո񣬷�ֹ���ֱ��ж�Ϊ����������� 
	cout<<s;
	return 0;
}
