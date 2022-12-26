//count����
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <algorithm> 
using namespace std;

int main()
{
  vector<int> l;
  for(int i=0; i<100; i++)
    l.push_back(i%20);
  int num=count(l.begin(),l.end(),9);//ͳ�Ƶ���9��Ԫ�ظ���
  cout<<num<<endl;
  return 0;
}

