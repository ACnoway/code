#include <cstdio>
#include <algorithm>
using namespace std;
struct S
{
    int x, y;
} a[500050];
int T, n, q,
    c[500050];
bool C(S a, S b) { return a.x < b.x; }
void M(int x)
{
    for (; x <= n; x += x & -x)
        ++c[x];
}
bool K(int k)
{
    int q = 0, s = 0;
    for (int i = 20, x, y; i >= 0; --i)
        if ((x = q + (1 << i)) <= n && (y = s + c[x]) <= k)
            q = x, s = y;
    return s == k;
}
bool F2()
{
    q = 0;
    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    for (int i = 1; i <= n; ++i)
        ++c[a[i].x];
    for (int i = 1; i <= n; ++i)
        if ((q += c[i]) * 2 == n)
            return 1;
    q = 0;
    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    for (int i = 1; i <= n; ++i)
        ++c[a[i].y];
    for (int i = 1; i <= n; ++i)
        if ((q += c[i]) * 2 == n)
            return 1;
    return 0;
}
bool F3()
{
    sort(a + 1, a + n + 1, C);
    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        M(n - a[i].y + 1);
        if (a[i].x != a[i + 1].x && K(n >> 1))
            return 1;
    }
    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    for (int i = n; i; --i)
    {
        M(a[i].y);
        if (a[i].x != a[i - 1].x && K(n >> 1))
            return 1;
    }
    return 0;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &a[i].x, &a[i].y);
        if (F2())
            puts("2");
        else if (F3())
            puts("3");
        else
            puts("4");
    }
    return 0;
}