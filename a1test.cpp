#include <bits/stdc++.h>
#define van long long
#define N 1000100
using namespace std;
van n, a[N], q, d[N];
van t[N * 4][2][2]; //线段树
void update(van p, van num)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            t[p][i][j] = -1e18;
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    if (l != 1 || k != 1 || d[num] * d[num + 1] >= 0)
                        t[p][i][j] = max(t[p][i][j], t[p * 2][i][k] + t[p * 2 + 1][l][j]);
        }
} //更新线段树p节点上的值
void add(van p, van l, van r, van where)
{
    if (l == r)
    {
        //		cout<<"add "<<l<<" "<<d[l]<<endl;
        t[p][1][1] = abs(d[l]);
        return;
    }
    van mid = l + r >> 1;
    if (where <= mid)
        add(p * 2, l, mid, where);
    if (where > mid)
        add(p * 2 + 1, mid + 1, r, where);
    update(p, mid);
} //更新线段树(单点修改)
van query(van x)
{
    return max(t[x][0][0], max(t[x][0][1], max(t[x][1][0], t[x][1][1])));
} //查询线段树上x节点的最大值
int main()
{
    //	ifstream ywhin("sjeckanje.in");
    //	ofstream ywhout("sjeckanje.out");
#define ywhin cin
#define ywhout cout
    ywhin >> n >> q;
    for (int i = 1; i <= n; i++)
        ywhin >> a[i];
    for (int i = 1; i <= n; i++)
        d[i] = i == 1 ? 0 : a[i] - a[i - 1], add(1, 1, n, i); //差分并插入线段树上
    while (q--)
    {
        van l, r, k;
        ywhin >> l >> r >> k;
        if (l != 1)
        {
            d[l] += k;
            add(1, 1, n, l);
        } //添加左端点
        if (r != n)
        {
            d[r + 1] -= k;
            add(1, 1, n, r + 1);
        }                         //添加右端点
        cout << query(1) << endl; //查询[1,n]的区间最值
    }
    return 0;
}