#include<iostream>
#include<cstdio>
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
void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
struct kuai
{
    int st,en,k;
}temp,now,x;
queue<kuai> q,q2;
bool v[200005];
int n,cnt,s=1;
int f[200005];
int main()
{
    n=read();
    for(int i=1;i<=n;++i) f[i]=read();
    f[n+1]=!f[n];
    for(int i=2;i<=n+1;++i){
        if(f[i]!=f[i-1]){
            //如果跟前一个果子品种不一样
            //就代表有一个新的块
            q.push((kuai){s,i-1,f[i-1]});
            s=i;
        }
    }
    cnt=n;
    //取完所有果子停止
    while(cnt){
        while(q.size()){
            //如果当前队列里还有没取完的块
            temp=q.front();
            q.pop();
            //判断当前果子是否被取出
            //因为在合并的时候直接更改开始编号，
            //不会对旧开始编号和新开始编号之间的果子进行判断是否取出
            while(v[temp.st]&&temp.st<=temp.en) temp.st++;
            if(temp.st>temp.en) continue;
            write(temp.st);
            putchar(' ');
            cnt--;
            //标记已经取出
            v[temp.st]=1;
            temp.st++;
            if(temp.st>temp.en) continue;
            //存到队列准备合并
            q2.push(temp);
        }
        putchar('\n');
        while(q2.size()){
            //把所有要合并的合并
            //先取出一个，跟其他的对比进行合并
            now=q2.front();
            q2.pop();
            while(q2.size()){
                x=q2.front();
                if(x.k==now.k){
                    //一样的话把结束编号往后延
                    now.en=x.en;
                    q2.pop();
                }
                //不一样就不用再往下找了，直接退出
                else break;
            }
            //把合并后的块存到原队列中
            q.push(now);
        }
    }
    return 0;
}