//输入
int P, Q, A[MAX_Q + 2];  //A中保存输入数据，下标从 1 开始

// dp[i][j] 是释放 (i,j)之间连续的所有囚犯，所需的最少金币数
int dp[MAX_Q + 1][MAX_Q + 2];

void solve() {
	//为了处理方便，将两端加入 A 中，即把左端当成 0号囚犯，右端当成 Q+1号囚犯
	// dp[0][Q+1]就是答案
	A[0] = 0;
	A[Q + 1] = P + 1;
	
	//初始化
	for (int q = 0; q <= Q; q++) {
		dp[q][q + 1] = 0;
	} 
	
	//从短的区间开始填充 dp
	for (int w = 2; w <= Q + 1; w++) {
		for (int i = 0; i + w <= Q + 1; i++) {
			//计算 dp[i][j]
			int j = i + w, t = INT_MAX;
			//枚举最初释放的囚犯，计算最小的费用
			for (int k = i + 1; k < j; k++) {
				t = min (t, dp[i][k] + dp[k][j]);
			} 
			
			//最初的释放还需要与所释放囚犯无关的 A[j]-A[i]-2枚金币
			dp[i][j] = t + A[j] - A[i] - 2; 
		}
	} 
	
	printf("%d\n",dp[0][Q+1]);
} 
 
