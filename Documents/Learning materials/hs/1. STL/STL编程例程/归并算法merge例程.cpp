//归并算法merge例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <algorithm> 
using namespace std;

void print(int x)
{
  cout<<x<<' ';
}

int main()
{
  int a[]= {2,3,5,12};
  int b[]= {9,81,711,5111,31111};
  int result[9];
  //升序归并
  merge(a,a+4,b,b+5,result);
  for_each(result,result+9,print);//for_each类似于for循环操作
  cout<<endl;
  int c[]= {9,8,7};
  int d[]= {8,3,1,-1};
  //降序归并
  merge(c,c+3,d,d+4,result,greater<int>());
  for_each(result,result+7,print);
  cout<<endl;
  return 0;
}

