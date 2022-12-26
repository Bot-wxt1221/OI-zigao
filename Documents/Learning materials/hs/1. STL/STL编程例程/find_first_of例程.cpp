//find_first_of����
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <algorithm> 
using namespace std;

int main()
{
  char *s1="abcdefu7ghijklmn";
  char *s2="zyx3yu7ys";
  char * i=find_first_of(s1,s1+strlen(s1),s2,s2+strlen(s2));
  cout<<"s1��һ��������s2���ַ�Ϊ"<<*i<<endl;//���u
  return 0;
}

