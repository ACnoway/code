#include <iostream>

using namespace std;

const int N = 600010, M = N * 25;

int a[N];

int max_id[M], s[N], tr[M][2], root[N], idx;

void insert(int i, int k, int p, int q)
{
    if (k < 0)
    {
        max_id[q] = i;
        return;
    }
    int v = s[i] >> k & 1;
    if (p)
        tr[q][v ^ 1] = tr[p][v ^ 1];
    tr[q][v] = ++idx;
    insert(i, k - 1, tr[p][v], tr[q][v]);
    max_id[q] = max(max_id[tr[q][0]], max_id[tr[q][1]]);
}

int query(int root, int C, int l)
{
    int p = root;
    for (int i = 23; i >= 0; i--)
    {
        int v = C >> i & 1;
        if (max_id[tr[p][v ^ 1]] >= l)
            p = tr[p][v ^ 1];
        else
            p = tr[p][v];
    }

    return C ^ s[max_id[p]];
}

int main()
{
    int n, m;
    cin >> n >> m;
    max_id[0] = -1;
    root[0] = ++idx;
    insert(0, 23, 0, root[0]);
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
        root[i] = ++idx;
        insert(i, 23, root[i - 1], root[i]);
    }

    for (int i = 1; i <= m; i++)
    {
        char o[2];
        cin >> o;
        if (*o == 'A')
        {
            int x;
            cin >> x;
            n++;
            s[n] = s[n - 1] ^ x;
            root[n] = ++idx;
            insert(i, 23, root[n - 1], root[n]);
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;
            cout << query(root[r - 1], s[n] ^ x, l - 1) << endl;
        }
    }
    return 0;
}