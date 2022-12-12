//pair例程2
#include <bits/stdc++.h>
using namespace std;
typedef pair<string, double> Record;//typedef简化pair的声明为Record

int main()
{
  Record p1 = make_pair("zxh", 100);
  Record p2;
  p2 = p1; //重载运算符"="
  cout<<p2.first<<' '<< p2.second<<endl;
  return 0;
}

