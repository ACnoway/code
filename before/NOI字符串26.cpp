#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char for_in[3][301];
int pos[2][501];
string s,s1,s2;
int main()
{
	scanf("%[^',']",for_in[0]); s=for_in[0]; getchar();
	scanf("%[^',']",for_in[1]); s1=for_in[1]; getchar();
	scanf("%s",for_in[2]); s2=for_in[2];
	int l=s2.size(),pos1=s.find(s1),pos2=s.find(s2),chang=0,ti=0;
	if(pos1+l>pos2||pos1<0||pos2<0){
		cout<<"-1"; return 0;
	}
	for(int i=s.size()-s2.size();i>=0;i--){
		string temp;
		temp=s.substr(i,l);
		if(temp==s2){
			cout<<i-pos1-s1.size();
			return 0;
		}
	}
	return 0;
}

