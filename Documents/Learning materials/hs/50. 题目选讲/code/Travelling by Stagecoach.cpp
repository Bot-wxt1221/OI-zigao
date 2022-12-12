//输入
int n, m, a, b;
int t[MAX_N];
int d[MAX_M][MAX_M];   //图的邻接矩阵表示（-1表示没有边）

//dp[S][v] := 到达城市 v 且剩下的车票集合为 S 所需要的最小花费
double dp[1 << MAX_N][MAX_M];

void solve() {
	for (int i = 0; i < 1 << n; i++) {
		fill(dp[i], dp[i] + m, INF);   //用足够大的值初始化 
	}
	dp[(1 << n) - 1][a - 1] = 0;
	double res = INF;
	for (int S = (1 << n) - 1; S >= 0; S--) {
		res = min(res, dp[S][b - 1]);
		for (int v = 0; v < m; v++) {
			for (int i = 0; i < n; i++) {
				if (S >> i & 1) {
					for (int u = 0; u < m; u++) {
						if (d[v][u] >= 0) {
							//使用车票 i，从 v 移动到 u
							dp[S & ~(1 << i)][u] = min(dp[S & ~(1 << i)][u], dp[S][v] +
														 (double)d[v][u] / t[i]);							 
						}
					}
				}
			}			
		}
	}
	if (res == INF) {
		//无法到达
		printf("Impossible\n");
	} else {
		printf("%.3f\n", res);
	}
}  
