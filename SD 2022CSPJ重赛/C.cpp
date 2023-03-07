#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
using namespace std;
inline int read(){
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
const int maxn=1000006;
int n,m,q;
//a[]�ʼ�ı���
//gen[i]�ǵ�һ������������ǣ���¼��iΪ�����������˶���
//zw[i]�ǵڶ�������������ǣ���¼��iֱ�������ĵ���˶���
int a[maxn],gen[maxn],zw[maxn];
//��ʽǰ���Ǵ��
struct node{
    int to,nxt;
}e[maxn<<1];
int id,head[maxn];
void addedge(int u,int v){
    e[++id].to=v;
    e[id].nxt=head[u];
    head[u]=id;
}
//x��ʾ��ǰ�ڵ㣬jia��ʾ�Ӹ�����������Ҫ�ӵģ�fa��ʾx�ĵ���˭
void dfs(int x,int jia,int fa){
    //�ȰѴ�������jia���������Լ���lt׼������ȥ
    jia+=gen[x];
    //Ȼ���Ҫ�ӵ��ȼӵ��Լ�����
    a[x]+=jia+zw[x];
    //Ȼ����Ǳ�����x���������б�
    int y;
    for(int i=head[x];i;i=e[i].nxt){
        y=e[i].to;
        //��Ϊ�����������Ҫע�ⲻ�ܻص�x�İ���
        if(y==fa){
            //�ǵð�x��zw������Ǹ���������
            //(��ʵ�����ѭ�������Ҳ�в�����һ����)
            a[fa]+=zw[x];
            continue;
        }
        //������һ�����ǵðѵڶ�����������Ǽ���
        a[y]+=zw[x];
        dfs(y,jia,x);
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int p,x,y;
    for(int i=1;i<n;++i){
        x=read();
        y=read();
        addedge(x,y);
        addedge(y,x);
    }
    m=read();
    while(m--){
        p=read();
        x=read();
        y=read();
        if(p==1){
            //��xΪ���������м�y��ֱ�Ӵ������ǣ����ѯ�ʵ�ʱ��ͳ��
            gen[x]+=y;
        }
        else{
            //���������
            zw[x]+=y;
        }
    }
    //dfs������
    dfs(1,0,0);
    q=read();
    while(q--){
        x=read();
        printf("%d\n",a[x]);
    }
    return 0;
}