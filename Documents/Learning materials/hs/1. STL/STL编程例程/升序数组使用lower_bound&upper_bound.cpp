//升序数组使用lower_bound/upper_bound示例
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int a[] = {1, 1, 2, 2, 3, 3, 3, 4, 4, 4};
  cout<< lower_bound(a, a+10, 0)-a <<endl; //输出下标0
  cout<< lower_bound(a, a+10, 1)-a <<endl; //输出下标0
  cout<< lower_bound(a, a+10, 3)-a <<endl; //输出下标4
  cout<< lower_bound(a, a+10, 4)-a <<endl; //输出下标7
  cout<< lower_bound(a, a+10, 5)-a <<endl; //输出下标10

  cout<< upper_bound(a, a+10, 0)-a <<endl; //输出下标0
  cout<< upper_bound(a, a+10, 1)-a <<endl; //输出下标2
  cout<< upper_bound(a, a+10, 3)-a <<endl; //输出下标7
  cout<< upper_bound(a, a+10, 4)-a <<endl; //输出下标10
  cout<< upper_bound(a, a+10, 5)-a <<endl; //输出下标10
  return 0;
}

