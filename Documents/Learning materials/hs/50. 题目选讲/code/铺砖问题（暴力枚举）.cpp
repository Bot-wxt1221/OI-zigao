//暴力枚举，每次从最左上方的空格处开始尝试放置，避免重复统计 
 
//输入
int n, m;
bool color[MAX_N][MAX_M];   //false: 白，true: 黑

//现在查看的格子是（i，j），used表示哪些格子已经被覆盖过
int rec(int i, int j, bool used[MAX_N][MAX_M]) {
	if (j == m) {
		//到下一行 
		return rec(i + 1, 0 , used);
	}
	
	if (i == n) {
		//已经覆盖了所有的空格
		return 1; 
	}
	
	if (used[i][j] || color[i][j]) {
		//不需要在（i，j）上放置砖块
		return rec(i, j + 1, used); 
	}
	
	//当前（i，j）是白色格子且未覆盖，尝试 2 种放法
	int res = 0;
	used[i][j] = true; 
	
	//横着放
	if (j + 1 < m && !used[i][j + 1]) && !color[i][j + 1]) {
		used[i][j + 1] = true;
		res += rec(i, j + 1, used);
		used[i][j + 1] = false;
	} 
	
	//竖着放
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
	memset(used, 0, sizeof(used));   //初始化为 false
	printf("%d\n", rec(0, 0, used)); 
}



