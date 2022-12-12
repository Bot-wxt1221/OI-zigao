const int dx[4] = {-1, -1, 1, 1},  dy = {-1, 0, -1, 0};
//����
int M, N;
char seat[MAX_M][MAX_N + 1];  //��λ

int V;                   //������ 
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

//������ͼ�����ƥ��
int bipartite_matching() {
	int res = 0;
	memset(match, -1, sizeof(match));
	for (int v = 0; v < V; v++) {
		if (match[v] < 0) {
			memset(used, 0, sizeof(used));
			if (dfs(v)) res++;
		}
	}
} 

void solve() {
	int num = 0;
	V = M * N;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (seat[y][x] == '.') {
				num++;
				for (int k = 0; k < 4; k++) {
					int x2 = x + dx[k], y2 = y + dy[k];
					if (0 <= x2 && x2 < N && 0 <= y2 && y2 < M && seat[y2][x2] == '.') {
						add_edge(x * M + y, x2 * M + y2);
					}
				}
			}
		}
	}
	printf("%d\n", num - bipartite_matching());	
} 
