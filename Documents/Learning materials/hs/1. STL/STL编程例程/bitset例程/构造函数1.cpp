//���캯��1
#include<bits/stdc++.h>
using namespace std;//ȫ��λ����512M�ڴ滷���������С�ɿ���5000������

int main()
{
  bitset<5000000> bin;//binΪλ���飬��ʼΪ0��һ��512M�ڴ�����ԼΪ500��
  bin[0]=1;//��Ϊ1
  bin[1]=true;
  bin[2]=0;//��Ϊ0
  bin[3]=false;
  cout<<bin[0]<<bin[1]<<bin[2]<<bin[3]<<bin[4];//��ӡ��11000
  return 0;
}

