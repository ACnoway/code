#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
std::vector<int> v;
int n;
int main()
{
	clock_t st,en;
	st=clock();
	//v.reserve(10000000);
	for(int i=1;i<=10000000;++i){
		v.insert(v.end(),i,1);
	}
	en=clock();
	cout<<en-st<<endl;
	//for(auto i:v) cout<<i<<' ';
	return 0;
}