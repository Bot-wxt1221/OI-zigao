#include <iostream>
#include <algorithm>  //sort()  stable_sort()
using namespace std;
int a[500], b[500], n, s = 0;
int main() 
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n); //�� n �������������� 
	for(int i = 0; i < n; i++)
	{
		if(a[i] == a[i+1]) continue; //���� 
		b[s++] = a[i];
	}
	cout << s << endl;
	for(int i = 0; i < s; i++) cout << b[i] << " ";
	return 0;
}
