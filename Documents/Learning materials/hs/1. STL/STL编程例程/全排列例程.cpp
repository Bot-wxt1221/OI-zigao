//ȫ��������
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <algorithm> 
using namespace std;

void print(int a[])
{
  for(int i=0; i<5; i++)
    cout<<a[i]<<" ";
  cout<<endl;
}

int main()
{
  int a[]= {3,5,6,7,9};
  //����������һ��ϣ�ʱ�临�Ӷ�Ϊn!,�ٶȽ���
  while(next_permutation(a,a+5))//��һ���
    print(a);
  cout<<endl;
  while(prev_permutation(a,a+5))//��һ���
    print(a);
  return 0;
}

