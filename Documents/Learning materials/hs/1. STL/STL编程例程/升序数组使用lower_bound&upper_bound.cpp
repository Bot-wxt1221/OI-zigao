//��������ʹ��lower_bound/upper_boundʾ��
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int a[] = {1, 1, 2, 2, 3, 3, 3, 4, 4, 4};
  cout<< lower_bound(a, a+10, 0)-a <<endl; //����±�0
  cout<< lower_bound(a, a+10, 1)-a <<endl; //����±�0
  cout<< lower_bound(a, a+10, 3)-a <<endl; //����±�4
  cout<< lower_bound(a, a+10, 4)-a <<endl; //����±�7
  cout<< lower_bound(a, a+10, 5)-a <<endl; //����±�10

  cout<< upper_bound(a, a+10, 0)-a <<endl; //����±�0
  cout<< upper_bound(a, a+10, 1)-a <<endl; //����±�2
  cout<< upper_bound(a, a+10, 3)-a <<endl; //����±�7
  cout<< upper_bound(a, a+10, 4)-a <<endl; //����±�10
  cout<< upper_bound(a, a+10, 5)-a <<endl; //����±�10
  return 0;
}

