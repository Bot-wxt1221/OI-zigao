//�鲢�㷨merge����
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <algorithm> 
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
  //����鲢
  merge(a,a+4,b,b+5,result);
  for_each(result,result+9,print);//for_each������forѭ������
  cout<<endl;
  int c[]= {9,8,7};
  int d[]= {8,3,1,-1};
  //����鲢
  merge(c,c+3,d,d+4,result,greater<int>());
  for_each(result,result+7,print);
  cout<<endl;
  return 0;
}

