//count例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <algorithm> 
using namespace std;

int main()
{
  vector<int> l;
  for(int i=0; i<100; i++)
    l.push_back(i%20);
  int num=count(l.begin(),l.end(),9);//统计等于9的元素个数
  cout<<num<<endl;
  return 0;
}

