#include<iostream>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int height[10001],shou,geshu=0;
	for(int x=0;x<=9;x++){
		cin>>height[x];
	} 
	cin>>shou;
	for(int y=0;y<=9;y++){
		if(height[y]<=(shou+30)) geshu+=1;
	}
	cout<<geshu;
	fclose(stdin);
	fclose(stdout);
	return 0;
 }

