typedef long long LL;

int prime[1000000];   //不超过1000000的第 i 个的素数
int p;                //素数的个数

//输入
LL A, B, P;

void solve() {
	int len = B - A + 1;
	init_union_find(len);    //初始化并查集
	
	for (int i = 0; i < p; i++) {
		//对不小于 P 的素数进行处理
		if (prime[i] >= P) {
			//不小于A的最小的prime[i]的倍数
			LL start = (A + prime[i] - 1) / prime[i] * prime[i];
			//不大于B的最大的prime[i]的倍数 
			LL end =  B / prime[i] * prime[i];
			
			for (LL j = start; j <= end; j += prime[i]) {
				//start和 j 属于同一个集合
				unite(start - A, j - A); 
			}
		} 
	} 
	int res = 0;
	for (LL i = A; i <= B; i++) {
		//find[i] == i时，i就是并查集的根
		//集合的个数等于根的个数
		if(find(i - A) == i -A) res++; 
	}
	printf("%d\n", res);
} 
