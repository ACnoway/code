#include<bits/stdc++.h>
using namespace std;
int s,a[100007];//这里取的10 0000，可以取更大
//但即使对于打表来说，时间也够长的了
int main()
{
	string a="dabcdefg";
    string b="dabc";
    cout<<a.find_last_of(b)<<endl;
	return 0;
}