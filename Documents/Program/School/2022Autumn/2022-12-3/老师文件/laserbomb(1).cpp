#include<iostream>
#include<cstdio>
using namespace std;

int f[5010][5010], n, m, r, c, x, y, z, ans;
short a[5010][5010];
int main() {
	freopen("laserbomb.in","r",stdin);
	freopen("laserbomb.out","w",stdout);
	cin >> n >> m;
	r = c = m;
	for(int i = 1; i <= n; i++)	{
		scanf("%d%d%d", &x, &y, &z);
		x++, y++;
		a[x][y] = z;
		r = max(r,x); c = max(c,y);
	}
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
			f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
	for(int i = m; i <= r; i++)
		for(int j = m; j <= c; j++)
			ans = max(ans, f[i][j] - f[i][j-m] - f[i-m][j] + f[i-m][j-m]);
	cout << ans << endl;
	fclose(stdin);	fclose(stdout);
	
	return 0;
}
