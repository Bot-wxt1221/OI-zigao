void solve() {
	int res = n + 1;
	int s = 0, t = 0, sum = 0;
	for (;;) {
		while (t < n && sum < S) {
			sum += a[t++];
		}
		if (sum < S) break;
		res = min(res, t - s);
		sum -= a[s++];
	}
	
	if (res > n) {
		//½â²»´æÔÚ
		res = 0; 
	}
	printf("%d\n", res);
}
