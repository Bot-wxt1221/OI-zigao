int dp[2][1 << MAX_M];   //DP���飨��������ѭ�����ã�

void solve() {
	int *crt = dp[0], *next = dp[1];
	crt[0] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			for (int used = 0; used < 1 << m; used++) {
				if ((used >> j & 1) || color[i][j]) {
					//����Ҫ�ڣ�i��j������ש��
					next[used] = crt[used & ~(1 << j)];		
				} else {
					//���� 2 �ַŷ�
					int res = 0;
					//���ŷ�
					if (j + 1 < m && !(used >> (j + 1) & 1) && !color[i][j + 1]) {
						res += crt[used | 1 << (j + 1)];
					} 
					//���ŷ�
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

