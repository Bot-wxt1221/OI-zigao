//���ϲ�������
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <algorithm> 
using namespace std;

void print(int c[])
{
  for(int i=0; i<10; i++) //Ϊ�ȶ�����
    cout<<c[i]<<' ';
  cout<<endl;
}

int main()
{
  int a[]= {3,3,17,22,23,24};
  int b[]= {9,22,24,33};
  int lena=sizeof(a)/sizeof(int);
  int lenb=sizeof(b)/sizeof(int);
  int c[]= {0,0,0,0,0,0,0,0,0,0};
  set_union(a,a+lena,b,b+lenb,c);//�󲢼�
  print(c);
  memset(c,0,sizeof(c));
  set_intersection(a,a+lena,b,b+lenb,c);//�󽻼�
  print(c);
  //��������������1������������2��Ԫ�أ�����д��c
  memset(c,0,sizeof(c));
  set_difference(a,a+lena,b,b+lenb,c);
  print(c);
  //�������죬��������ͬʱ�������������Ԫ�أ�����д��c
  memset(c,0,sizeof(c));
  set_symmetric_difference(a,a+lena,b,b+lenb,c);
  print(c);
  return 0;
}

