//��������ʹ��lower_bound/upper_bound�Ĵ���ʾ��
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int a[] = {4, 4, 3, 3,  2, 2,  1, 1};
  cout << lower_bound(a, a+8, 4,greater<int>())-a <<endl; // ��� 0
  cout << upper_bound(a, a+8, 4,greater<int>())-a <<endl; // ��� 2
  cout << lower_bound(a, a+8, 1,greater<int>())-a <<endl; // ��� 6
  cout << upper_bound(a, a+8, 1,greater<int>())-a <<endl; // ��� 8
  cout << lower_bound(a, a+8, 3,greater<int>())-a <<endl; // ��� 2
  cout << upper_bound(a, a+8, 3,greater<int>())-a <<endl; // ��� 4
  return 0;
}

