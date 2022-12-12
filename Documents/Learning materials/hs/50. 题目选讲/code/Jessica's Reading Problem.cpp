//输入
int P;
int a[MAX_P];

void solve() {
	//计算全部知识点的总数
	
	set<int> all;
	for (int i = 0; i < P; i++) {
		all.insert(a[i]);
	} 
	int n = all.size();
	
	//利用滑动窗口思想来求解
	int s = 0, t = 0, num = 0;
	map<int,int> count;   //知识点-->出现次数的映射
	int res = P;
	for (;;) {
		while (t < P && num < n) {
			if (count[a[t++]]++ == 0) {
				//出现新的知识点
				num++; 
			}
		} 
		if (num < n) break;
		res = min(res, t - s);
		if(--count[a[s++]] == 0) {
			//某个知识点的出现次数为 0了
			num--; 
		}
	} 
	 
	printf("%d\n", res);
} 
