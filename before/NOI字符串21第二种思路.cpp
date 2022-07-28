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
	//在字符串两端加空格，防止出现判断字母是否出现而不是单词是否出现。
	//若只在字符串后加空格，则会出现单词a前有字母依旧被替换的情况 
	int l=a.size();
	while(s.find(a)!=-1/*判断字符串s里面是否含有单词a*/){
		s.replace(s.find(a),l,b); //替换单词a为单词b
	}
	s.erase(s.begin(),s.begin()+1);s.erase(s.end()--,s.end());
	//删除前面和后面的空格，防止出现被判断为输出错误的情况 
	cout<<s;
	return 0;
}
