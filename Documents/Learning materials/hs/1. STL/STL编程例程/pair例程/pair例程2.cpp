//pair����2
#include<bits/stdc++.h>
using namespace std;
typedef pair<string, double> Record;//typedef��pair������ΪRecord

int main()
{
  Record p1 = make_pair("zxh", 100);
  Record p2;
  p2 = p1; //���������"="
  cout<<p2.first<<' '<< p2.second<<endl;
  return 0;
}

