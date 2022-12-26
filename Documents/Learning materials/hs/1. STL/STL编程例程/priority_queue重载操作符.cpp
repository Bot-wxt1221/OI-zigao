//priority_queue���ز�����
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <queue> 
using namespace std;

struct cmp
{
  bool operator() (const int &a,const int &b)//����"()"������
  {
    return a>b;//��С����������">"��������"<"
  }
};

int main()
{
  priority_queue<int,vector<int>,cmp>que1;
  priority_queue<int,vector<int> >que2;
  int a[]= {1,3,4,2,5,0,6};
  for(int i=0; i<7; i++)
  {
    que1.push(a[i]);
    que2.push(a[i]);
  }
  cout<<"que1:";
  while(!que1.empty())
  {
    cout<<que1.top()<<" ";
    que1.pop();
  }
  cout<<endl<<"que2:";
  while(!que2.empty())
  {
    cout<<que2.top()<<" ";
    que2.pop();
  }
  return 0;
}

