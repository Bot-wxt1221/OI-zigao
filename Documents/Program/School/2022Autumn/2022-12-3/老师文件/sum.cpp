#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[300010], q[300010], n, m;
long long sum[300010], ans;

int main() {
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)	{
		scanf("%d",&a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	//sum[i]-min{sum[j]|i-m~i-1};
	/*
	  ����ĳһ�� i������Ҫ�ҵ�һ��j(i-j<=m)��ʹ��sum[i]-sum[j]���
	  ��������� j1<j2, ����sum[j1]>sum[j2],��ôj1����ֱ��������Ҳ��������� j �������
	  �����ǵ��������ģ��������ǿ�����һ������������ά����� j ������ 
	*/
	int l = 1, r = 1;
	q[l] = 0; //save j
	for(int i = 1; i <= n; i++)	{
		while(l <= r && q[l] < i-m) l++;
		ans = max(ans, sum[i] - sum[q[l]]);
		while(l <= r && sum[q[r]] >= sum[i]) r--;
		q[++r] = i;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
