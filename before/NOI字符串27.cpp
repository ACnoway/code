#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
string a;
int main()
{
	getline(cin,a);
	vector<char> b;
	int ti=0;
	for(int i=0;i<a.size();i++){
		if(a[i]!=' '&&i<a.size()-1){
			b.insert(b.begin(),a[i]);
			ti++;
		}
		else{
			if(a[i]!=' '){
				b.insert(b.begin(),a[i]);
				ti++;
			}
			
			for(int o=0;o<ti;o++){
				printf("%c",b[o]);
			}
			printf(" ");
			ti=0;
		}
	}
	return 0;
}

