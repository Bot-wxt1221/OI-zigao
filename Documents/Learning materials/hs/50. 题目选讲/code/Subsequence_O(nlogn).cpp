//输入
int n, S;
int a[MAX_N];

int sum[MAX_N + 1];

void solve() {
	//计算 sum
	for (int i = 0; i < n; i++) {
		sum[i + 1] = s[i] + a[i]; 
	} 
	
	if(sum[n] < S) {
		//解不存在 
		printf("0\n");
		return ;
	}
	
	int res = 0;
	for (int s = 0; sum[s] + S <= sum[n]; s++) {
		//利用二分搜索求出 t
		int t = lower_bound(sum + s, sum + n, sum[s] + S) - sum;
		res = min(res, t - s); 
	}
	
	printf("%d\n", res);
} 
