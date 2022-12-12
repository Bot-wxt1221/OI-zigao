//全排列例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <algorithm> 
using namespace std;

void print(int a[])
{
  for(int i=0; i<5; i++)
    cout<<a[i]<<" ";
  cout<<endl;
}

int main()
{
  int a[]= {3,5,6,7,9};
  //产生所有下一组合，时间复杂度为n!,速度较慢
  while(next_permutation(a,a+5))//下一组合
    print(a);
  cout<<endl;
  while(prev_permutation(a,a+5))//上一组合
    print(a);
  return 0;
}

