#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a1[1]={1},a2[2][2]={{1,2},{4,3}},a3[3][3]={{1,2,3},{8,9,4},{7,6,5}},a4[4][4]={{1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7}},a5[5][5]={{1,2,3,4,5},{16,17,18,19,6},{15,24,25,20,7},{14,23,22,21,8},{13,12,11,10,9}},a6[6][6]={{1,2,3,4,5,6},{20,21,22,23,24,7},{19,32,33,34,25,8},{18,31,36,35,26,9},{17,30,29,28,27,10},{16,15,14,13,12,11}},a7[7][7]={{1,2,3,4,5,6,7},{24,25,26,27,28,29,8},{23,40,41,42,43,30,9},{22,39,48,49,44,31,10},{21,38,47,46,45,32,11},{20,37,36,35,34,33,12},{19,18,17,16,15,14,13}},a8[8][8]={{1,2,3,4,5,6,7,8},{28,29,30,31,32,33,34,9},{27,48,49,50,51,52,35,10},{26,47,60,61,62,53,36,11},{25,46,59,64,63,54,37,12},{24,45,58,57,56,55,38,13},{23,44,43,42,41,40,39,14},{22,21,20,19,18,17,16,15}},a9[9][9]={{1,2,3,4,5,6,7,8,9},{32,33,34,35,36,37,38,39,10},{31,56,57,58,59,60,61,40,11},{30,55,72,73,74,75,62,41,12},{29,54,71,80,81,76,63,42,13},{28,53,70,79,78,77,64,43,14},{27,52,69,68,67,66,65,44,15},{26,51,50,49,48,47,46,45,16},{25,24,23,22,21,20,19,18,17}};
	int n;
	cin>>n;
	if(n==1){
		cout<<"  1";
	}
	else if(n==2){
		printf("%3d%3d\n%3d%3d",a2[0][0],a2[0][1],a2[1][0],a2[1][1]);
	}
	else if(n==3){
		for(int i=0;i<3;i++){
			for(int o=0;o<3;o++){
				printf("%3d",a3[i][o]);
			}
			if(i!=2) cout<<endl;
		}
	}
	else if(n==4){
		for(int i=0;i<4;i++){
			for(int o=0;o<4;o++){
				printf("%3d",a4[i][o]);
			}
			if(i!=3) cout<<endl;
		}
	}
	else if(n==5){
		for(int i=0;i<5;i++){
			for(int o=0;o<5;o++){
				printf("%3d",a5[i][o]);
			}
			if(i!=4) cout<<endl;
		}
	}
	else if(n==6){
		for(int i=0;i<6;i++){
			for(int o=0;o<6;o++){
				printf("%3d",a6[i][o]);
			}
			if(i!=5) cout<<endl;
		}
	}
	else if(n==7){
		for(int i=0;i<7;i++){
			for(int o=0;o<7;o++){
				printf("%3d",a7[i][o]);
			}
			if(i!=6) cout<<endl;
		}
	}
	else if(n==8){
		for(int i=0;i<8;i++){
			for(int o=0;o<8;o++){
				printf("%3d",a8[i][o]);
			}
			if(i!=7) cout<<endl;
		}
	}
	else if(n==9){
		for(int i=0;i<9;i++){
			for(int o=0;o<9;o++){
				printf("%3d",a9[i][o]);
			}
			if(i!=8) cout<<endl;
		}
	}
 	return 0;
}

