#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}
int cnt[130];
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
    string s;
    while(1){
        getline(cin,s);
        if(s=="END") return 0;
        for(int i=0;i<128;++i) cnt[i]=0;
        while(!q.empty()) q.pop();
        for(char x:s){
            ++cnt[(int)x];
        }
        for(int i=0;i<128;++i) if(cnt[i]) q.push(cnt[i]);
        long long res=0;
        while(q.size()>1){
            int t1=q.top();q.pop();
            int t2=q.top();q.pop();
            q.push(t1+t2);
            res+=t1+t2;
        }
        printf("%d %lld %.1lf\n",s.size()*8,res,(double)s.size()*8.0/(double)res);
    }
    return 0;
}
