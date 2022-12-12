#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[300010], q[300010], n, m;
long long sum[300010], ans;

int main() {
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)	{
		scanf("%d",&a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	//sum[i]-min{sum[j]|i-m~i-1};
	/*
	  对于某一个 i，我们要找到一个j(i-j<=m)，使得sum[i]-sum[j]最大。
	  假设如果有 j1<j2, 而且sum[j1]>sum[j2],那么j1可以直接抛弃，也就是在这个 j 的序列里，
	  必须是单调递增的，所以我们可以用一个单调队列来维护这个 j 的序列 
	*/
	int l = 1, r = 1;
	q[l] = 0; //save j
	for(int i = 1; i <= n; i++)	{
		while(l <= r && q[l] < i-m) l++;
		ans = max(ans, sum[i] - sum[q[l]]);
		while(l <= r && sum[q[r]] >= sum[i]) r--;
		q[++r] = i;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
