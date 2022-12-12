#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
struct node
{
int dis, val;
}a[500010];
ll f[500010];
int ssav[500010], sl, sr, n, d, k;
int q[500010];
ll chk(int g)
{
memset(f, 0, sizeof(f));
memset(q, 0, sizeof(q));
int l, r, s, t;
if (g < d)
{
s = d - g; t = d + g;
}else
{
s = 1; t = d + g;
}
// 每次跳的距离区间[s, t]
l = r = 1;
q[1] = 0;
f[0] = 0;
sl = 1; sr = 0;
int i;
for (i = 1; i <= n; ++i)
{
for (int k = sl; k <= sr; ++k)
{
if (a[ ssav[k] ].dis <= a[i].dis - s )
{
++sl;
while (l <= r && f[ssav[k]] >= f[q[r]]) --r;
q[++r] = ssav[k];
}else break;
}
while (l <= r && a[ q[l] ].dis < a[i].dis - t) ++l;
if (l <= r && (a[ q[l] ].dis >= a[i].dis - t && a[ q[l] ].dis <= a[i].dis - s))
{
ssav[++sr] = i;
f[i] = f[q[l]] + a[i].val;
}
}
ll ans = -1e12;
for (int i = 1; i <= n; ++i) ans = max(ans, f[i]);
return ans >= k;
}
int main()
{
		freopen("jump6.in", "r", stdin);
//	freopen("jump.out", "w", stdout);
scanf("%d%d%d", &n, &d, &k);
for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].dis, &a[i].val);
int l = 0, r = 500000 + 1;
while (l < r)
{
int g = (l + r) >> 1;
if (chk(g)) r = g; else l = g + 1;
}
if (l == 500000 + 1) printf("-1\n"); else printf("%d\n", l);
return 0;
}
