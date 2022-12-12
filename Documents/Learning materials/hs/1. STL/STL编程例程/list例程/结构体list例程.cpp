//结构体list例程
#include <bits/stdc++.h>
using namespace std;

struct student
{
  char *name;
  int age;
  char *city;
};

int main()
{
  student s[]=
  {
    {"张三",18,"浙江"},
    {"李四",19,"北京"},
    {"王二",18,"上海"}
  };
  list<student>l;
  l.push_back(s[0]);//插入元素
  l.push_back(s[1]);
  l.push_back(s[2]);
  student x= {"刘四",19,"新疆"};
  l.push_front(x);//插入到首位，复杂度为O(1)
  l.insert(l.begin(),x);//插入任意位置,时间复杂度O(1)
  //l.pop_front();//删除首元素
  //l.pop_back();//删除尾元素
  l.erase(l.begin());
  //l.erase(l.begin(),l.end());//删除区间的元素
  for(list<student>::iterator i=l.begin(); i!=l.end(); i++)
    cout<<(*i).name<<"  "<<(*i).age<<"  "<<(*i).city<<"\n";
  return 0;
}

