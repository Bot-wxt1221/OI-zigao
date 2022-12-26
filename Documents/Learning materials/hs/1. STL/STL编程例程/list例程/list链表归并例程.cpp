//list�����鲢����
#include<bits/stdc++.h>
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
  l2.splice(l2.begin(),l1);//��l1��ȫ��Ԫ�ع鲢��L2��L1���
  ii=l2.begin()++;
  l1.splice(l1.begin(),l2,ii);//��l2��iiλ�õ�Ԫ�ع鲢��l1��l2ԭԪ��ɾ��
  print(l1);
  print(l2);
  //swap(l1,l2);//����l1,l2
  l1.push_back(8);
  l1.push_back(8);
  l1.push_back(35);
  l1.unique();//��ȥ�����ظ�Ԫ��
  l2.push_back(30);
  l1.sort();//����
  l2.sort();
  print(l1);
  l2.merge(l1);//L1�鲢��l2��������������,���������ļ��鲢�㷨merge
  print(l2);
  return 0;
}

