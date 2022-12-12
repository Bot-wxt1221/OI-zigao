//����
int N, K; 
int R[MAX_K], C[MAX_K]; 

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
	V = N * 2;
	for (int i = 0; i < K; i++) {
		add_edge(R[i] - 1, N + C[i] - 1);		
	}
	printf("%d\n", bipartite_matching());
} 

