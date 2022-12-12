//����
int n;
int A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];

int CD[MAX_N * MAX_N];   // C�� D�����ֵ���Ϸ���

void solve() {
	//ö�ٴ�C�� D��ȡ�����ֵ����з���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			CD[i * n + j] = C[i] + D[j];
		}
	} 
	sort(CD, CD + n * n);
	
	long long res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cd = -(A[i] + B[j]);
			//ȡ�� C �� D �к�Ϊ cd �Ĳ���
			res +=upper_bound(CD, CD + n * n, cd) - lower_bound(CD, CD + n * n, cd); 
		}
	}
	
	printf("%lld\n", res);
} 
