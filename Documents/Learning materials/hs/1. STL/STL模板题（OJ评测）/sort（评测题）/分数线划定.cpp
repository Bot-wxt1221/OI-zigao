#include <bits/stdc++.h>
using namespace std;
struct stu
{
	int id, s;
} e[5001];
int n, m, minm;

int cmp(stu a, stu b)
{
	if(a.s == b.s) return a.id < b.id;
	return a.s > b.s;
}

int main()
{
	cin >> n >> m;
	minm = m * 150 / 100;
	minm = min(minm, n);
	for(int i = 0; i < n; i++) cin >> e[i].id >> e[i].s;
	sort(e, e + n, cmp);  
	int flag = minm - 1;  //�����ͷֵ��±� 
	for(int i = minm; i < n; i++) //������������ͷ���ͬ���������������� 
		if(e[i].s == e[flag].s) minm++;
	cout << e[minm-1].s << " " << minm << endl;
	for(int i = 0; i < minm; i++)
		cout << e[i].id << " " << e[i].s << endl;
	return 0;
}
