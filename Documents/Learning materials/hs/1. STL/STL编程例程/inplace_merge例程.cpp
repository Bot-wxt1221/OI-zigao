//inplace_merge例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <algorithm> 
using namespace std;

void print(int x)
{
  cout<<x<<' ';
}

int main()
{
  int a[]= {2,3,5,12,1,8,9,711,5111,31111};
  const int len=sizeof(a)/sizeof(int);
  //升序内部归并
  inplace_merge(a,a+4,a+len);
  for_each(a,a+len,print);
  cout<<endl;
  //降序内部归并
  int b[]= {100,80,60,40,20,10,90,70,50,30};
  const int len2=sizeof(b)/sizeof(int);
  inplace_merge(b,b+6,b+len,greater<int>());
  for_each(b,b+len2,print);
  cout<<endl;
  return 0;
}

