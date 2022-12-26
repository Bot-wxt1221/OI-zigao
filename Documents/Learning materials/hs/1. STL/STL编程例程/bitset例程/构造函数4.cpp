//���캯��4
#include<bits/stdc++.h>
using namespace std;

int main()
{
  string temp="1010111101";
  bitset<10> bin(temp,4);//�ӵ�4λ��ʼȡֵ��������0λ
  for(int i=0; i<=9; i++)
    cout<<bin[i];//��ӡ��1011110000��ע�⣬�Ǵ����������������
  return 0;
}

