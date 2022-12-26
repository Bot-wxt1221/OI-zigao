//���캯��5
#include<bits/stdc++.h>
using namespace std;

int main()
{
  string temp="1010111101";
  bitset<10> bin(temp,4,5);//�ӵ�4��Ԫ�ؿ�ʼ����ȡ5��Ԫ�أ���������0
  for(int i=0; i<=9; i++)
    cout<<bin[i];//��ӡ��0111100000��ע�⣬�Ǵ����������������
  return 0;
}

