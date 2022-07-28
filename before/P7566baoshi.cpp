#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	long long n,m=0,c=0,o=0,it=0;
	cin>>n;
	for(long long i=0;i<n;i++){
		string temp;
		cin>>temp;
		switch(temp[0]){
			case 'M':{
				m++;
				break;
			}
			case 'C':{
				c++;
				break;
			}
			case 'O':{
				o++;
				break;
			}
			case 'I':{
				it++;
				break;
			}
		}
	}
	long long total=m*c*o+m*c*it+m*it*o+it*c*o;
	cout<<total;
	return 0;
}
