#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int main()
{
	map<string,string>d;
	string words[100001];
	while(1){
		char temp,word[100],mean[100];
		string tempm;
		mean[0]=getchar();
		if(mean[0]=='\n'){
			break;
		}
		else{
			tempm=mean[0];
			scanf("%[^' ']%s",mean,&word);
		}
		getchar();
		string m=mean,w=word;
		m=tempm+m;
		d[w]=m;
	}
	int t=0;
	while(1){
		string tempw;
		char temp,word[101];
		word[0]=getchar();
		if(word[0]=='\n'){
			break;
		}
		else{
			tempw=word[0];
			scanf("%[^'\n']",word);
		}
		getchar();
		string w=word;
		w=tempw+w;
		words[t++]=w;
	}
	for(int i=0;i<t;i++){
		if(d[words[i]]!="") cout<<d[words[i]]<<endl;
		else cout<<"eh"<<endl;
	}
	return 0;
}
