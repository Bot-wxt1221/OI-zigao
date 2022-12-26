//����������vector
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int j;
  vector<int> v;
  v.reserve(30);                         //�������ݿռ��С
  for(int i=0; i<10; i++)
    v.push_back(i);                      //β�˲�����Ԫ��
  vector<int>::iterator i;               //����vector�ĵ�����i
  for(i=v.begin(); i!=v.end(); i++)      //����������
    cout<<*i<<" ";
  cout<<"\n v�е�Ԫ�ظ���:"<<v.size()<<'\n';//Ԫ��ʵ�ʸ���
  reverse(v.begin(),v.end());            //��ת
  for(i=v.begin(); i!=v.end(); i++)      //����������
    cout<<*i<<" ";
  v.clear();                             //ȫ�����Ԫ��
  cout<<"\n v�Ƿ�Ϊ��:"<<v.empty()<<'\n'; //�ж��Ƿ�Ϊ��
  return 0;
}

