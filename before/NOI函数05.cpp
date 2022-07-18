#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
int main()
{
	string a,b;
	cin>>a; getchar(); getline(cin,b);
	for(int i=0;i<a.size();i++){
		a[i]=tolower(a[i]);
	}
	for(int i=0;i<b.size();i++){
		b[i]=tolower(b[i]);
	}
	a=' '+a+' '; b=' '+b+' ';
	if(b.find(a)==-1){
		cout<<"-1";
		return 0;
	}
	int place=b.find(a),t=0;
	while(b.find(a)!=-1){
		t++;
		b.replace(b.find(a),b.find(a)+a.size()," ");
	}
	cout<<t<<" "<<place;
	return 0;
}

