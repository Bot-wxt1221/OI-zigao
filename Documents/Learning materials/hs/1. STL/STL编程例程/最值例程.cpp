//��ֵ����
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <algorithm> 
using namespace std;

bool strComp(const char *s1,const char *s2)
{
  return strcmp(s1,s2)<0?1:0;
}

int main()
{
  cout<<min((char*)"green",(char*)"girl",strComp)<<endl;//��ӡgirl
  cout<<min(100,30)<<endl;
  cout<<max(100,30)<<endl;
  list<int> l;
  l.push_back(13);
  l.push_back(6);
  l.push_back(9);
  l.push_back(3);
  l.push_back(20);
  l.push_back(18);
  l.push_back(1);
  cout<<*min_element(l.begin(),l.end())<<endl;//������СԪ��
  cout<<*max_element(l.begin(),l.end())<<endl;//�������Ԫ��
  //�ֵ���Ƚϴ�С
  char * s1="house";
  char *s2="book";
  const int len1=sizeof("house")/sizeof(char);
  const int len2=sizeof("book")/sizeof(char);
  bool f=lexicographical_compare(s1,s1+len1,s2,s2+len2);//���ֵ���Ƚ�������
  if (f)
    cout<<"house��bookǰ"<<endl;
  else
    cout<<"house��book��"<<endl;
  return 0;
}

