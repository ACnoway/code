#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m,big=0,small=10;
	double score=0,most=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int o=0;o<m;o++){
			int ping;
			cin>>ping;
			if(ping>big) big=ping;
			if(ping<small) small=ping;
			score+=ping;
		}
		score=(score-big-small)/(m-2);
		if(score>most) most=score;
		score=0; big=0; small=10; 
	}
	printf("%.2lf",most);
	return 0;
}

