vector<int> G[MAX_V];    //ͼ���ڽӱ��ʾ
int match[MAX_V];        //��ƥ��Ķ���
bool used[MAX_v];        //DFS���õ��ķ��ʱ��

//��ͼ������һ������ u �� v �ı�
void add_edge(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
} 

//ͨ��DFSѰ������·
bool dfs(int v) {
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		int u = G[v][i], w = match[u];
		if (w < 0 || !used[w] && dfs(w)) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;	
} 

const int dx[4] = {-1, 0, 0, 1}, dy = {0, -1, 1, 0};

//����
int X, Y;
char field[MAX_X][MAX_Y + 1];  //��Ҫ���Ǳ��� \0 ����Ŀռ�

vector<int> dX, dY;  //�ŵ�����
vector<int> pX, pY;  //�˵�����
int dist[MAX_X][MAX_Y][MAX_X][MAX_Y]   //�������

//ͨ��BFS�����������
void bfs(int x, int y, int d[MAX_X][MAX_Y]) {
	queue<int> qx, qy;
	d[x][y] = 0;
	qx.push(x);
	qy.push(y);
	while (!qx.empty()) {
		x = qx.front(); qx.pop();
		y = qy.front(); qy.pop();
		for (int k = 0; k < 4; k++) {
			int x2 = x + dx[k], y2 = y + dy[k];
			if (0 <= x2 && x2 < X && 0 <= y2 && y2 < Y && field[x2][y2] == '.' && d[x2][y2] < 0) {
				d[x2][y2] = d[x][y] + 1;
				qx.push(x2);
				qy.push(y2);
			}
		} 
	}
}

void solve() {
	int n = X * Y;
	dX.clear(); dY.clear();
	pX.clear(); pY.clear();
	memset(dist, -1, sizeof(dist));
	
	//���㵽�����ŵ��������
	for (int x = 0; x < X; x++) {
		for (int y = 0; y < Y; y++) {
		   if (field[x][y] == 'D') {
				dX.push_back(x);
				dY.push_back(y);
				bfs(x, y, dist[x][y]);
		   }else if (fileld[x][y] == '.') {
				pX.push_back(x);
				pY.push_back(y);
		   }
		}
	} 
	
	//��ͼ 
	int d = dX.size(), p = pX.size();	
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < p; j++) {
			int h = dist[dX[i]][dY[i]][pX[j]][pY[j]];
			if (h >= 0) {
				for (int k = h; k <= n; k++){ 
					add_edge(k - 1) * d + i, n * d + j); 
				} 
			}
		}
	} 
	
	//��������˰�ȫ�������������ʱ��
	if (p == 0) {
		printf ("0\n");
		return;
	} 
	int num = 0;
	memset(match, -1, sizeof(match));
	for (int v = 0; v < n * d; v++) {
		memset(used, 0, sizeof(used));
		if (dfs(v)){
			if (++num == p) {
				printf ("%d\n", v / d + 1);
				return;
			}	
		}	
	}
	
	//����ʧ��
	printf("impossible\n"); 
} 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	 
} 
