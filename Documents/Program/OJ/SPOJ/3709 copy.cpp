#include<iostream>
#include<cstdio>
#define int long long 
using namespace std;
const int N = 500005;
#define y(A) f[(A)] - s[A] + (A) * ar[(A) + 1]
//
//y = kx + f[i] - s[i]
//y - kx = f[i] - s[i]
//y - kx + s[i] = f[i] 
int f[N], ar[N], s[N];
int q[N], x[N], y[N];
int fr = 0, re = 0; 
signed main(){
//由dp方程推出来的公式:
//f[j] - s[j] + ja[j + 1] = ia[j + 1] + f[i] - s[i]  
	int T = 1;
	scanf("%lld", &T);
	while(T--){
  		for(int i = 0; i < N; ++i){//由于有多组数据，所以初始化 
			f[i] = ar[i] = s[i] = q[i] = x[i] = y[i] = 0;
		}
		fr = re = 0;
		
		int n, k;
		scanf("%lld%lld", &n, &k);
		if(k == 0){
			printf("0\n");
			continue;
		}
		for(int i = 1; i <= n; i++) f[i] = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &ar[i]);
			s[i] = s[i-1] + ar[i];
		} 
//		for(int i = 1; i < k; i++) f[i] = s[i] - i * ar[1];
		
		//因为j的取值是 k ~ i - k，所以当i小于2k的时候没有选组 
		for(int i = 1; i < min(N, 2 * k); i++){
			f[i] = s[i] - i * ar[1];
			x[i] = ar[i + 1]; y[i] = y(i);
		}
		q[re++]=0;
		x[0] = 0;y[0] = y(0);//表示不分组的选择 
		for(int i = 2 * k; i <= n; i++){
			while(re - fr >= 2 && (y[q[re - 1]] - y[q[re - 2]]) * (x[i - k] - x[q[re - 1]]) >= 
				(y[i - k] - y[q[re - 1]]) * (x[q[re - 1]] - x[q[re - 2]])){
				re--;
			}//交叉相乘，斜率递增 
			
			q[re++] = i - k;//由于j的取值最大在i - k，所以加入的选择应该是i - k 	
//			while(re - fr >= 2 && (y[q[fr]] - y[q[fr + 1]]) / (x[q[fr]] - x[q[fr + 1]]) < i ){
//				fr++;
//			}
			//原本应该是上面这样。由于 (x[q[fr]] - x[q[fr + 1]])一定是非正数，所以移项之后方向改变 
			while(re - fr >= 2 && (y[q[fr]] - y[q[fr + 1]]) >= i * (x[q[fr]] - x[q[fr + 1]])){
				fr++;
			}
			int k = q[fr];
			f[i] = y(k) - i * ar[k + 1] + s[i];
			/*
			y = kx + f[i] -s[i]
			f[i] = y - kx + s[i]
			*/ 
			x[i] = ar[i + 1];
			y[i] = y(i);
		}
		printf("%lld\n", f[n]);
		 
	}
	return 0;
}
/* 
1
7 0
1 2 3 4 5 6 7
*/ 
/*
f[i] = f[j] + s[i] - s[i] + (i - j) * a[j + 1]
*/