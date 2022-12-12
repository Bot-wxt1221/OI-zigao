//结构体容器的vector
#include <bits/stdc++.h>
using namespace std;

struct stu
{
  int x,y;
};

int main()
{
  int j;
  vector<stu> v1;                     //结构体容器
  vector<stu> v2;
  struct stu a= {1,2};
  struct stu b= {2,3};
  struct stu c= {4,5};
  v1.push_back(a);
  v1.push_back(b);
  v1.push_back(c);
  v2.push_back(c);
  v2.push_back(b);
  v2.push_back(a);
  swap(v1,v2);                        //两结构体元素交换
  for(int i=0; i<v1.size(); i++)      //输出v1所有元素
    cout<<v1[i].x<<" "<<v1[i].y<<endl;
  cout<<"\n";
  for(int i=0; i<v2.size(); i++)      //输出v2所有元素
    cout<<v2[i].x<<" "<<v2[i].y<<endl;
  return 0;
}

