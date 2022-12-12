//find_first_of例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <algorithm> 
using namespace std;

int main()
{
  char *s1="abcdefu7ghijklmn";
  char *s2="zyx3yu7ys";
  char * i=find_first_of(s1,s1+strlen(s1),s2,s2+strlen(s2));
  cout<<"s1第一个出现在s2的字符为"<<*i<<endl;//输出u
  return 0;
}

