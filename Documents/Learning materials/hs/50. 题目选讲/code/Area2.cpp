#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 500 + 10;
int W, H, N;
int X1[maxn], X2[maxn], Y1[maxn], Y2[maxn]; int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

//填充用
bool fld[maxn * 6][maxn * 6];

//对x1, x2进行坐标离散化，并返回离散化之后的宽度
int compress(int *x1, int *x2, int w)
{
	vector<int> xs;
	
	for (int i = 0; i < N; i++){
		for (int d = -1; d <= 1; d++){
			int tx1 = x1[i] + d, tx2 = x2[i] + d; 
			if (1 <= tx1 && tx1 <= W)
				xs.push_back(tx1);
			if (1 <= tx2 && tx2 <= W)
				xs.push_back(tx2);
			}
		}
	sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    
    for (int i = 0; i < N; i++){
    	x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin(); 
		x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }
    return xs.size();
}

void solve()
{
	//坐标离散化
    W = compress(X1, X2, W);
    H = compress(Y1, Y2, H);
    
    //填充有直线的部分
    memset(fld, 0, sizeof(fld));     
	for (int i = 0; i < N; i++){
		for (int y = Y1[i]; y <= Y2[i]; y++){
			for (int x = X1[i]; x <= X2[i]; x++){
				fld[y][x] = true;
			}
		}
	}
	
	//求区域的个数
    int ans = 0;
    for (int y = 0; y < H; y++){
    	for (int x = 0; x < W; x++){
    		if (fld[y][x])
				continue;
			ans++;
			
			//宽度优先搜索
			queue<pair<int, int> > que; 
			que.push(make_pair(x, y));
			while (!que.empty()){
				int sx = que.front().first, sy = que.front().second; 
				que.pop();
				
				for (int i = 0; i < 4; i++){
					int tx = sx + dx[i], ty = sy + dy[i];
					if (tx < 0 || W <= tx || ty < 0 || H <= ty)
						continue;
					if (fld[ty][tx])
						continue;
					que.push(make_pair(tx, ty));
					fld[ty][tx] = true;
				}
			}
		}		
    } 
    printf("%d\n", ans);
}
	
int main()
{
	scanf("%d%d%d", &W, &H, &N);     
	for (int i = 0; i < N; i++)
		scanf("%d", &X1[i]);
    for (int i = 0; i < N; i++)
		scanf("%d", &X2[i]);
    for (int i = 0; i < N; i++)
		scanf("%d", &Y1[i]);
    for (int i = 0; i < N; i++)
		scanf("%d", &Y2[i]);     
	solve();
	
    return 0;
}
