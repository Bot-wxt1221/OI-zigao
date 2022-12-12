//includes例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <algorithm> 
using namespace std;

int main()
{
  int a[]= {3,9,17,22,23,24};
  int b[]= {9,22,24,3};
  int lena=sizeof(a)/sizeof(int);
  int lenb=sizeof(b)/sizeof(int);
  if(includes(a,a+lena,b,b+lenb))
    cout<<"B是A的子集合"<<endl;
  else
    cout<<"B不是A的子集合"<<endl;
  return 0;
}

