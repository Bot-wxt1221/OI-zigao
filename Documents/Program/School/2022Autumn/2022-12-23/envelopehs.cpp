#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int NUM = 100005;
struct T {
	int w, h;
	bool operator < (const T &L) const {
		if(w == L.w) return h > L.h;
		return w < L.w;
	}
} EN[NUM];
int dp[NUM];

int LIS(int n,  struct T a[NUM]) {
	int len = 1;
	dp[len] = a[1].h;
	for(int i = 2; i <= n; i++) {		
		if(dp[len] == a[i].h) continue;
		if(dp[len] < a[i].h) dp[++len] = a[i].h;
		else *upper_bound(dp + 1, dp + len + 1, a[i].h) = a[i].h;
	}
	return len;
}

int LIS_nlogn_1(int n, struct T a[NUM]) {
	int len;
	fill(dp + 1, dp + n + 1, INF);
	for(int i = 1; i <= n; i++)  {
		//�� a[i]�滻 dp �����е�һ�����ڵ��� a[i]����
		*lower_bound(dp + 1, dp + n + 1, a[i].h) = a[i].h; 
	}
	len = lower_bound(dp + 1, dp + n + 1, INF) - (dp + 1);	
	return len;
}
/*
4
1 1
2 3
3 1
4 2
*/
int main() {
	// freopen("envelope1.in" , "r", stdin);
	// freopen("envelope11.out", "w", stdout);
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d", &EN[i].w, &EN[i].h);
	sort(EN + 1, EN + n + 1);	
	printf("%d\n", LIS_nlogn_1(n, EN));	
	printf("%d\n", LIS(n, EN));		
	return 0;
}

/*
���룺
4
5 4
6 4
6 7
2 3
���
3
*/
