//集合操作例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <algorithm> 
using namespace std;

void print(int c[])
{
  for(int i=0; i<10; i++) //为稳定排序
    cout<<c[i]<<' ';
  cout<<endl;
}

int main()
{
  int a[]= {3,3,17,22,23,24};
  int b[]= {9,22,24,33};
  int lena=sizeof(a)/sizeof(int);
  int lenb=sizeof(b)/sizeof(int);
  int c[]= {0,0,0,0,0,0,0,0,0,0};
  set_union(a,a+lena,b,b+lenb,c);//求并集
  print(c);
  memset(c,0,sizeof(c));
  set_intersection(a,a+lena,b,b+lenb,c);//求交集
  print(c);
  //求差，所有属于区间1而不属于区间2的元素，排序写入c
  memset(c,0,sizeof(c));
  set_difference(a,a+lena,b,b+lenb,c);
  print(c);
  //集合求异，把两个不同时属于两个区间的元素，排序写入c
  memset(c,0,sizeof(c));
  set_symmetric_difference(a,a+lena,b,b+lenb,c);
  print(c);
  return 0;
}

