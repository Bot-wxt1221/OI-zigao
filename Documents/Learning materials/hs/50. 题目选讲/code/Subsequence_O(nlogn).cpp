//����
int n, S;
int a[MAX_N];

int sum[MAX_N + 1];

void solve() {
	//���� sum
	for (int i = 0; i < n; i++) {
		sum[i + 1] = s[i] + a[i]; 
	} 
	
	if(sum[n] < S) {
		//�ⲻ���� 
		printf("0\n");
		return ;
	}
	
	int res = 0;
	for (int s = 0; sum[s] + S <= sum[n]; s++) {
		//���ö���������� t
		int t = lower_bound(sum + s, sum + n, sum[s] + S) - sum;
		res = min(res, t - s); 
	}
	
	printf("%d\n", res);
} 
