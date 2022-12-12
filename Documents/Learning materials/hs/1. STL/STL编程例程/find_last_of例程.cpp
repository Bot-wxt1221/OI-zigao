//find_last_of例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <algorithm> 
using namespace std;

int main()
{
  string str = "Mississippi";
  int index;
  index = str.find_last_of('s');//输出6
  cout<<index<<endl;
  return 0;
}

