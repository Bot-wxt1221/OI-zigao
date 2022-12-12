int dp[2][1 << MAX_M];   //DP数组（滚动数组循环利用）

void solve() {
	int *crt = dp[0], *next = dp[1];
	crt[0] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			for (int used = 0; used < 1 << m; used++) {
				if ((used >> j & 1) || color[i][j]) {
					//不需要在（i，j）放置砖块
					next[used] = crt[used & ~(1 << j)];		
				} else {
					//尝试 2 种放法
					int res = 0;
					//横着放
					if (j + 1 < m && !(used >> (j + 1) & 1) && !color[i][j + 1]) {
						res += crt[used | 1 << (j + 1)];
					} 
					//竖着放
					if (i + 1 < n && !color[i + 1][j]) {
						res += crt[used | 1 << j];
					}  
					next[used] = res % M;
				}						 
			}
			swap(crt, next);
		}
	}
	printf("%d\n", crt[0]);
} 

