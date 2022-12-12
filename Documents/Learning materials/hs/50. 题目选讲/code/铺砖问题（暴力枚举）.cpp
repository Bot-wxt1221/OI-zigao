//����ö�٣�ÿ�δ������Ϸ��Ŀո񴦿�ʼ���Է��ã������ظ�ͳ�� 
 
//����
int n, m;
bool color[MAX_N][MAX_M];   //false: �ף�true: ��

//���ڲ鿴�ĸ����ǣ�i��j����used��ʾ��Щ�����Ѿ������ǹ�
int rec(int i, int j, bool used[MAX_N][MAX_M]) {
	if (j == m) {
		//����һ�� 
		return rec(i + 1, 0 , used);
	}
	
	if (i == n) {
		//�Ѿ����������еĿո�
		return 1; 
	}
	
	if (used[i][j] || color[i][j]) {
		//����Ҫ�ڣ�i��j���Ϸ���ש��
		return rec(i, j + 1, used); 
	}
	
	//��ǰ��i��j���ǰ�ɫ������δ���ǣ����� 2 �ַŷ�
	int res = 0;
	used[i][j] = true; 
	
	//���ŷ�
	if (j + 1 < m && !used[i][j + 1]) && !color[i][j + 1]) {
		used[i][j + 1] = true;
		res += rec(i, j + 1, used);
		used[i][j + 1] = false;
	} 
	
	//���ŷ�
	if (i + 1 < n && !used[i + 1][j] && !color[i + 1][j]) {
		used[i + 1][j] = true;
		res += rec(i, j + 1, used);
		used[i + 1][j] = false;
	} 
	
	used[i][j] = false;
	return res % M;	
} 

void solve() {
	bool used[MAX_N][MAX_M];
	memset(used, 0, sizeof(used));   //��ʼ��Ϊ false
	printf("%d\n", rec(0, 0, used)); 
}



