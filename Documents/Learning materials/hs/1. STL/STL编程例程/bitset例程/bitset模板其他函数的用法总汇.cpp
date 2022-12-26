/*
bitsetģ�������������÷��ܻ�
*/
#include<bits/stdc++.h>
using namespace std;
string temp="1010111101";
bitset<10> bin(temp);

void out()
{
  for(int i=0; i<=9; i++)
    cout<<bin[i];
  cout<<endl;
}

int main()
{
  out();
  cout<<endl<<bin.any()<<endl;//�Ƿ������Ϊ1��λ��
  cout<<bin.none()<<endl;//�Ƿ�ȫ��Ϊ0����any()�෴
  cout<<bin.count()<<endl;//������Ϊ1�ĸ���
  cout<<bin.size()<<endl;//�ܳ���
  bin.flip();//������λ����ȡ��
  out();
  bin.flip(0);//����λȡ��
  out();
  cout<<bin.operator[](2)<<endl;//��ȡ��2λ��ֵ
  bin.set();//������λȫ��Ϊ1
  out();
  bin.reset();//������λȫ��Ϊ0
  out();
  bin.set(0);//����0λ��Ϊ1
  out();
  bin.reset(0);//����0λ��Ϊ0
  out();
  cout<<bin.test(0)<<endl;//�жϵ�0λ�Ƿ�Ϊ1
  bin.set(0);
  int x=bin.to_ulong();//תΪ����1��ע���������ȡֵ�������𳬹�long�ͷ�Χ
  cout<<x<<endl;
  return 0;
}

