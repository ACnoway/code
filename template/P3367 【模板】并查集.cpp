#include<iostream>
using namespace std;
int n,m;
int p[10004];//记录点的祖先
int find(int x){
    //查找祖先
    if(p[x]!=x) p[x]=find(p[x]);
    //上面的是路径压缩，防止成一条链
    return p[x];
}
int main()
{
    cin>>n>>m;
    //n是节点数，m是操作数
    for(int i=0;i<=n;++i) p[i]=i;
    //初始化祖先数组，让每个点的祖先都是它本身，此时是一个森林的状态
    int x,y,z;
    //x和y是要操作的点，z是操作类型
    for(int i=0;i<m;++i){
        cin>>z>>x>>y;
        if(z==1){
            //合并，把x的祖先归到y的祖先下面
            p[find(x)]=find(y);
        }
        else{
            //查找，如果x和y的祖先一样就输出
            if(find(x)==find(y)) cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
    return 0;
}