#include <iostream>
#include <cstdio>
#define INF 999999999
using namespace std;
inline int in(){
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}
int data[200][200],d,n,sum,Max=-INF;
int main(){
	d=in();
	n=in();
	for (int i=1;i<=n;i++){
		int x,y;
		x=in();
		y=in();
		data[x+20][y+20]=in();
	}
	for (int i=0;i<=128;i++)
		for (int j=0;j<=128;j++){
			int t=0;
			for (int k=i-d+20;k<=i+d+20;k++)
				for (int l=j-d+20;l<=j+d+20;l++){
					t+=data[k][l];
				}
			if (t>Max){
				Max=t;
				sum=1;
			}
			else if (t==Max) sum++;
		}
	printf("%d %d\n",sum,Max);
	return 0;
}