//https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-T2131

#include<iostream>
#include<set> //��set����ʵ��ȥ��������
using namespace std;
set <int> a;
int n, num, b[100], s = 0;
int main() 
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> num;
		a.insert(num);
	}
	set<int> :: iterator it;	
	cout << a.size() << endl;
	for(it = a.begin(); it != a.end(); it++)
		cout << *it << " ";
		
	return 0;
}
