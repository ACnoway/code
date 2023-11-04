#include <bits/stdc++.h>

#define For(i, l, r) for (register int i = (l), i##end = (int)(r); i <= i##end; ++i)
#define Fordown(i, r, l) for (register int i = (r), i##end = (int)(l); i >= i##end; --i)
#define Rep(i, r) for (register int i = (0), i##end = (int)(r); i < i##end; ++i)
#define Set(a, v) memset(a, v, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(a))
#define debug(x) cout << #x << ": " << (x) << endl
#define Travel(i, u, v) for (int i = Head[u], v = to[i]; i; v = to[i = Next[i]])

using namespace std;

typedef long long ll;

template<typename T> inline bool chkmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

inline int read() {
	int x(0), sgn(1); char ch(getchar());
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') sgn = -1;
	for (; isdigit(ch); ch = getchar()) x = (x * 10) + (ch ^ 48);
	return x * sgn;
}

void File() {
	freopen ("division.in", "r", stdin);
	freopen ("division.out", "w", stdout);
}

const int N = 2e5 + 1e3, M = N << 1;

int n, Head[N], Next[M], to[M], e = 1;

inline void add_edge(int u, int v) {
	to[++ e] = v; Next[e] = Head[u]; Head[u] = e;
}

int sz[N], fa[N]; ll val[M];

int dep[N], deg[N];

void Dfs_Init(int u) {
	sz[u] = 1;
	dep[u] = dep[fa[u]] + 1;
	Travel(i, u, v) if (v != fa[u]) {
		++ deg[u];
		fa[v] = u; Dfs_Init(v); sz[u] += sz[v];
		val[i] = val[i ^ 1] = 1ll * sz[v] * (n - sz[v]);
	}
}

ll ans[N]; int cur, choose[N];

vector<int> trans[N];

inline void change(int u, int ban) {
	ans[cur] += val[choose[u]]; choose[u] = 0;
	Rep (p, trans[u].size()) {
		int i = trans[u][p];
		if (to[i] == ban) continue;
		if (val[i] > val[choose[u]]) {
			choose[u] = i; break;
		}
	}
	ans[cur] -= val[choose[u]];
}

void Calc(int u) {
	Travel(i, u, v) if (v != fa[u]) {
		ans[v] = ans[u]; cur = v; 
		change(u, v); change(v, 0); 
		Calc(v); cur = 0; 
		change(u, 0); change(v, u);
	}
}

int main() {

	File();

	n = read();
	For (i, 1, n - 1) {
		int u = read(), v = read();
		add_edge(u, v); add_edge(v, u);
	}

	Dfs_Init(1);

	For (i, 1, n - 1) ans[1] += val[i << 1];
	cur = 1; 
	For (i, 1, n) {
		Travel(j, i, v) trans[i].push_back(j);
		sort(trans[i].begin(), trans[i].end(), 
				[&](const int &lhs, const int &rhs) { return val[lhs] > val[rhs]; } );
		change(i, fa[i]); 
	}

	Calc(1);

	For (i, 1, n)
		printf ("%lld\n", ans[i]);

	cerr << "maxdep: " << *max_element(dep + 1, dep + n + 1) << endl;
	cerr << "maxdeg: " << *max_element(deg + 1, deg + n + 1) << endl;

	return 0;
}
