//random_shuffle例程 
#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int>v;
  for(int i=0; i<=9; i++)
    v.push_back(i);
  random_shuffle(v.begin(),v.end());//对vector随机排序
  for(int i=0; i<v.size(); i++)
    cout<<v[i]<<" ";
  cout<<endl;
  int a[10];
  for(int i=0; i<=9; i++)
    a[i]=10*i;
  random_shuffle(a,a+10);           //对数组随机排序 
  for(int i=0; i<=9; i++)
    cout<<a[i]<<" ";
  return 0;
}

