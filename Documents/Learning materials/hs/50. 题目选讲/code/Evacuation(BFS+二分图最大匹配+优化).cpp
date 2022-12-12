vector<int> G[MAX_V];    //图的邻接表表示
int match[MAX_V];        //所匹配的顶点
bool used[MAX_v];        //DFS中用到的访问标记

//向图中增加一条连接 u 和 v 的边
void add_edge(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
} 

//通过DFS寻找增广路
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

//输入
int X, Y;
char field[MAX_X][MAX_Y + 1];  //不要忘记保存 \0 所需的空间

vector<int> dX, dY;  //门的坐标
vector<int> pX, pY;  //人的坐标
int dist[MAX_X][MAX_Y][MAX_X][MAX_Y]   //最近距离

//通过BFS计算最近距离
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
	
	//计算到各个门的最近距离
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
	
	//建图 
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
	
	//求解所有人安全逃脱所需的最少时间
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
	
	//逃脱失败
	printf("impossible\n"); 
} 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	 
} 
