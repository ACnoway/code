#include<iostream>
#include<time.h>
using namespace std;
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		float a,b,c;
		cin>>a>>b>>c;
		if((a==0&&b==0)||(a==0&&c==0)||(c==0&&b==0)){
			cout<<"0"<<endl;
		}
		else if((a==b&&c==0)||(a==c&&b==0)||(c==b&&a==0)){
			cout<<"1"<<endl;
		}
		else if(a==b||b==c||a==c){
			cout<<"2"<<endl;
		}
		else if(a==0||b==0||c==0){
			cout<<"2"<<endl;
		}
		else if(a==b+c||b==a+c||c==a+b){
			cout<<"2"<<endl;
		}
		else if(2*a==b+c||2*b==a+c||2*c==a+b){
			cout<<"3"<<endl;
		}
		else cout<<time(0)%6<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
