//binary_search例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <algorithm> 
using namespace std;

int main()
{
  int a[]= {3,9,17,22,23,24};
  const int len=sizeof(a)/sizeof(int);
  if(binary_search(a,a+len,24))
    cout<<"数组包含24"<<endl; //结果是错误的
  else
    cout<<"数组不包含24"<<endl;
  return 0;
}

