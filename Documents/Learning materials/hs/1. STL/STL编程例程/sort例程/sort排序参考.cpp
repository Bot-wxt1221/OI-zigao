//sort����ο�
#include<bits/stdc++.h>//ʹ������ͷ�#include�д#in#includegorithm>��#include <functional> 
//#include<functional>
//functional�ṩ�����µĻ���ģ��ıȽϺ�������
//equal_to<Type>�����ڡ�
//not_equal_to<Type>�������ڡ�
//greater<Type>�����ڡ�
//greater_equal<Type>�����ڵ��ڡ�
//less<Type>��С�ڡ�
//less_equal<Type>��С�ڵ��ڡ�
//#include<algorithm>
//#include<iostream>
using namespace std;

void print(int a[],int n)
{
  for(int i=0; i<n; i++)
    cout<<a[i]<<' ';
  cout<<endl;
}

int main()
{
  int a[]= {-1,9,-34,100,45,2,98,32};
  const int len=sizeof(a)/sizeof(int);
  sort(a,a+len);//��С��������
  //sort(a,a+len,less<int>());//��Ҳ����ʵ����С��������
  print(a,len);

  sort(a,a+len,greater<int>());//�ɴ�С����
  print(a,len);
  
  sort(a,a+len,less<int>());//��С��������
  print(a,len);
  return 0;
}

