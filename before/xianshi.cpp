#include<iostream>
using namespace std;
char b[100]={0};
int main(){
	string a0[5][3]={{"XXX"},{"X.X"},{"X.X"},{"X.X"},{"XXX"}},a1[5][3]={{"..X"},{"..X"},{"..X"},{"..X"},{"..X"}},a2[5][3]={{"XXX"},{"..X"},{"XXX"},{"X.."},{"XXX"}},a3[5][3]={{"XXX"},{"..X"},{"XXX"},{"..X"},{"XXX"}},a4[5][3]={{"X.X"},{"X.X"},{"XXX"},{"..X"},{"..X"}},a5[5][3]={{"XXX"},{"X.."},{"XXX"},{"..X"},{"XXX"}},a6[5][3]={{"XXX"},{"X.."},{"XXX"},{"X.X"},{"XXX"}},a7[5][3]={{"XXX"},{"..X"},{"..X"},{"..X"},{"..X"}},a8[5][3]={{"XXX"},{"X.X"},{"XXX"},{"X.X"},{"XXX"}},a9[5][3]={{"XXX"},{"X.X"},{"XXX"},{"..X"},{"XXX"}};
	int a;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	for(int o=0;o<5;o++){
		for(int i=0;i<a;i++){
			if(b[i]-48==0){
				for(int t=0;t<3;t++) cout<<a0[o][t];
				if(i!=a-1) cout<<".";
			}
			else if(b[i]-48==1){
				for(int t=0;t<3;t++) cout<<a1[o][t];
				if(i!=a-1) cout<<".";
			}
			else if(b[i]-48==2){
				for(int t=0;t<3;t++) cout<<a2[o][t];
				if(i!=a-1) cout<<".";
			}
			else if(b[i]-48==3){
				for(int t=0;t<3;t++) cout<<a3[o][t];
				if(i!=a-1) cout<<".";
			}
			else if(b[i]-48==4){
				for(int t=0;t<3;t++) cout<<a4[o][t];
				if(i!=a-1) cout<<".";
			}
			else if(b[i]-48==5){
				for(int t=0;t<3;t++) cout<<a5[o][t];
				if(i!=a-1) cout<<".";
			}
			else if(b[i]-48==6){
				for(int t=0;t<3;t++) cout<<a6[o][t];
				if(i!=a-1) cout<<".";
			}
			else if(b[i]-48==7){
				for(int t=0;t<3;t++) cout<<a7[o][t];
				if(i!=a-1) cout<<".";
			}
			else if(b[i]-48==8){
				for(int t=0;t<3;t++) cout<<a8[o][t];
				if(i!=a-1) cout<<".";
			}
			else if(b[i]-48==9){
				for(int t=0;t<3;t++) cout<<a9[o][t];
				if(i!=a-1) cout<<".";
			}
		}
	if(o!=4) cout<<endl;
	}
	return 0;
}

