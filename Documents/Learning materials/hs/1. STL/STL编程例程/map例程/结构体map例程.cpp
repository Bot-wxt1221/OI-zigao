//结构体map例程
#include <bits/stdc++.h>
using namespace std;

struct Info                             //学生信息结构体
{
  char *xm;                             //姓名
  int y;                                //年份
  char *d;                              //地址
};

struct Record                           //学生记录结构体
{
  int id;                               //学号作键值
  Info sf;                              //学生信息作映照数据
};

int main()
{
  Record srArray[]=
  {
    {4,"Li",21,"beijing"},
    {2,"wang",29,"shanghai"},
    {3,"zhang",30,"shengzheng"}
  };
  map<int,Info, greater<int> >m;        //按键值由大到小排序
  for(int j=0; j<3; j++)                //装入三个学生信息
    m[srArray[j].id]=srArray[j].sf;
  Record s1= {5,"Ling",23,"XINJIANG"};
  m.insert(make_pair(s1.id,s1.sf));     //插入新生信息
  map<int,Info>::iterator i;
  for(i=m.begin(); i!=m.end(); i++)     //正向遍历
    cout<<(*i).first<<' '<<(*i).second.xm<<' '<<(*i).second.d<<'\n';
  i=m.find(2);                          //查找键值为2的记录并输出
  cout<<"键值2："<<(*i).second.xm<<' '<<(*i).second.d;
  return 0;
}

