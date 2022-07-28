#include<iostream>
#include<cmath>
using namespace std;
int K[1522]={0},hf[40][40]={{0},{0}};
int main()
{
	int N;
	cin>>N;
	int hang=0,lie=(N/2),n=N*N,z=N-1;
	hf[hang][lie]=1;
	for(int i=2;i<=n;i++){
		if(hang==0&&lie!=N-1){
			hf[z][lie+1]=i;
			hang=z;
			lie++;
		}
		else if(lie==z&&hang!=0){
			hf[hang-1][0]=i;
			hang--;
			lie=0;
		}
		else if(hang==0&&lie==z){
			hf[hang+1][lie]=i;
			hang++;
		}
		else if(hang!=0&&lie!=z){
			if(hf[hang-1][lie+1]==0){
				hf[hang-1][lie+1]=i;
				hang--;
				lie++;
			}
			else{
				hf[hang+1][lie]=i;
				hang++;
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int x=0;x<N;x++){
			cout<<hf[i][x];
			if(x!=z) cout<<" ";
		}
		if(i!=z) cout<<endl;
	}
	return 0;
}

