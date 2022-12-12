//�ڽӵĸ��ӵ�����
const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

//����
int M, N;
int tile[MAX_M][MAX_N];

int opt[MAX_M][MAX_N];   //�������Ž�
int flip[MAX_M][MAX_N];  //�����м���

//��ѯ(x,y)����ɫ
int get(int x, int y) {
	int c = tile[x][y];
	for (int d = 0; d < 5; d++) {
		int x2 = x + dx[d], y2 = y + dy[d];
		if (0 <= x2 && x2 < M && 0 < y2 && y2 < N) {
			c += flip[x2][y2];
		}
	}
	return c % 2;
} 

//����� 1 ��ȷ������µ���С��������
//�����ڽ�Ļ����� -1
int calc() {
	//����ӵ� 2 �п�ʼ�ķ�ת����
	for (int i = 1; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (get(i-1, j) != 0) {
				//(i-1,j)�Ǻ�ɫ�Ļ�������뷭ת�������
				flip[i][j] = 1; 
			}
		}
	}
	
	//�ж����һ���Ƿ�ȫ��
	for (int j = 0; j < N; j++) {
		if (get(M - 1, j) !=0 ) {
			//�޽�
			return -1; 
		}
	} 
	
	//ͳ�Ʒ�ת�Ĵ���
	int res = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			res += flip[i][j];
		}
	} 
	return res;
} 

void solve() {
	int res = -1;
	
	//�����ֵ����Ե�һ�е����п�����
	for (int i = 0; i < 1 << N; i++) {
		memset(flip, 0 , sizeof(flip));
		for (int j = 0; j < N; j++) {
			flip[0][N - j - 1] = i >> j & 1;
		}
		int num = calc();
		if (num >= 0 && (res < 0 || res > num)) {
			res = num;
			memcpy(opt, flip, sizeof(flip));
		}		
	} 
	
	if (res < 0) {
		//�޽�
		printf("IMPOSSIBLE\n");		 
	} else {
	  for (int i = 0; i < M; i++) {
	  	for (int j = 0; j < N; j++) {
	  		printf("%d%c", opt[i][j], j + 1 == N ? '\n' : ' ');
	  	}
	  }
	}
}



