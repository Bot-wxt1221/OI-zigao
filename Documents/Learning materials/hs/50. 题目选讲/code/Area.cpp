//����
int W, H, N;
int X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N];

//�����
bool fld[MAX_N * 6][MAX_N * 6];

//��x1��x2����������ɢ������������ɢ��֮��Ŀ��
int compress(int *x1, int *x2, int w) {
	vector<int> xs;
	
	for (int i = 0; i < N; i++) {
		for (int d = -1; d <= 1; d++) {
			int tx1 = x1[i] + d, tx2 = x2[i] + d;
			if(1 <= tx1 && tx1 <= w) xs.push_back(tx1);
			if(1 <= tx2 && tx2 <= w) xs.push_back(tx2);
		}
	} 
	
	//ȥ�� 
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()),xs.end());
	
	//����ѹ���������Ϳ�� 
	for(int i = 0; i <= N; i++) {
		x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
		x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.bedin();
	}
	
	return xs.size();	
} 

void solve() {
	//������ɢ��
	W = compress(X1, X2, W);
	H = compress(Y1, Y2, H);
	
	//�����ֱ�ߵĲ���
	memset(fld, 0, sizeof(fld));
	for (int i = 0; i < N; i++) {
		for (int y = Y1[i]; y <= Y2[i]; y++) {
			for (int x = X1[i]; x <= X2[i]; x++) {
				fld[y][x] = true;
			}
		}
	} 
	
	//������ĸ���
	int ans = 0;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if(fld[y][x]) continue;
			ans++;
			
			//�����������
			queue<pair<int, int> > que;
			que.push(make_pair(x, y));
			while (!que.empty()) {
				int sx = que.front().first, sy = que.front().second;
				que.pop();
				
				for (int i = 0; i < 4; i++) {
					int tx = sx + dx[i], ty = sy + dy[i];
					if (tx < 0 || W <= tx || ty < 0 || H <= ty) continue;
					if (fld[ty][tx]) continue;
					que.push(make_pair(tx, ty));
					fld[ty][tx] = true;
				}
			}			 
		}
	} 
	
	printf("%d\n", ans)
}








