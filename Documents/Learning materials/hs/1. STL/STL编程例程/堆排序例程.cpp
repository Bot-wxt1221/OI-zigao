//����������
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <algorithm> 
using namespace std;

void show(vector<int> h)
{
  for(int i=0; i!=h.size(); i++)
    cout<<h[i]<<" ";
  cout<<endl;
}

int main()
{
  int a[9]= {0,1,2,3,4,8,9,3,5};
  vector<int> V(a,a+9);

  make_heap(V.begin(),V.end());//���ѣ�Ĭ��ΪLess,�����Ԫ�ط��ڵ�һ��
  //make_heap(V.begin(),V.end(),greater<int>());//����,��СԪ�ط��ڵ�һ��
  show(V);

  V.push_back(7);
  push_heap(V.begin(),V.end());//������һ��Ԫ����ĩβ��Ȼ�����µ�������
  show(V);

  pop_heap(V.begin(),V.end());//�ѶѶ�Ԫ��ȡ�����ŵ�ĩβ����ԭ��ĩβԪ��ȥ���
  show(V);
  cout<<V.back()<<endl;
  V.pop_back();
  show(V);

  sort_heap(V.begin(),V.end());//��С���������Ͳ�����һ���Ϸ���heap��
  show(V);
  return 0;
}

