//�ṹ��priority_queue���ز�����
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <queue> 
using namespace std;

struct Info
{
  string name;
  float score;
  bool operator <(const Info &a) const
  {
    return a.score<score;//��score��С����������"<",������">"
  }
} ;

int main()
{
  priority_queue<Info> pq;
  Info info;
  info.name="Alice";
  info.score=98;
  pq.push(info);
  info.name="Jone";
  info.score=92;
  pq.push(info);
  info.name="Kate";
  info.score=95.5;
  pq.push(info);
  while(pq.empty()!=true)
  {
    cout<<pq.top().name<<": "<<pq.top().score<<endl;
    pq.pop();
  }
  return 0;
}

