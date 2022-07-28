#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string a;
		char last;
		getline(cin,a);
		switch(a[0]){
			case 'a':{
				for(int i=2;i<a.size();i++){
					if(a[i]==' ') a[i]='+';
				}
				break;
			}
		}
	}
	return 0;
}

