#include<iostream>
#include<cstring>
using namespace std;
const int N = 510 , M = 100010;
int n1,n2,m;
int h[N],ne[M],e[M],idx;
bool st[N];
int match[N];

void add(int a , int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void init()
{
    memset(h,-1,sizeof h);
}

int find(int x)
{
    //遍历自己喜欢的女孩
    for(int i = h[x] ; i != -1 ;i = ne[i])
    {
        int j = e[i];
        if(!st[j])//如果在这一轮模拟匹配中,这个女孩尚未被预定
        {
            st[j] = true;//那x就预定这个女孩了
            //如果女孩j没有男朋友，或者她原来的男朋友能够预定其它喜欢的女孩。配对成功
            if(!match[j]||find(match[j]))
            {
                match[j] = x;
                return true;
            }

        }
    }
    //自己中意的全部都被预定了。配对失败。
    return false;
}
int main()
{
    init();
    cin>>n1>>n2>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }


    int res = 0;
    for(int i = 1; i <= n1 ;i ++)
    {  
         //因为每次模拟匹配的预定情况都是不一样的所以每轮模拟都要初始化
          memset(st,false,sizeof st);
        if(find(i)) 
          res++;
    }  

    cout<<res<<endl;
}