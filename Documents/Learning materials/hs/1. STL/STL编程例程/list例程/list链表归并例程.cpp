//list链表归并例程
#include <bits/stdc++.h>
using namespace std;

void print(list<int> l)
{
  list<int>::iterator i;
  for(i=l.begin(); i!=l.end(); i++)
    cout<<*i<<" ";
  cout<<endl;
}

int main()
{
  list<int>l1;
  for(int j=10; j>=0; j--)
    l1.push_back(j);

  list<int>l2;
  list<int>::iterator ii;
  l2.splice(l2.begin(),l1);//将l1的全部元素归并到L2，L1清空
  ii=l2.begin()++;
  l1.splice(l1.begin(),l2,ii);//将l2的ii位置的元素归并到l1，l2原元素删除
  print(l1);
  print(l2);
  //swap(l1,l2);//交换l1,l2
  l1.push_back(8);
  l1.push_back(8);
  l1.push_back(35);
  l1.unique();//除去连续重复元素
  l2.push_back(30);
  l1.sort();//排序
  l2.sort();
  print(l1);
  l2.merge(l1);//L1归并到l2，两链表需排序,具体见后面的见归并算法merge
  print(l2);
  return 0;
}

