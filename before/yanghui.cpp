#include<iostream>
using namespace std;
int tr[21][21]={{0},{0}};
int main()
{
	int n;
	cin>>n;
	tr[0][0]=1;
	for(int i=1;i<20;i++){
		tr[i][0]=1;
		for(int t=1;t<=i;t++){
			tr[i][t]=tr[i-1][t-1]+tr[i-1][t];
		}
	}
	for(int i=0;i<n;i++){
		for(int t=0;t<=i;t++){
			cout<<tr[i][t];
			if(t!=i) cout<<" ";
		}
		if(i!=n-1) cout<<endl;
	}
	return 0;
}

