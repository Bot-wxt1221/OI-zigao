//map例程2
#include <bits/stdc++.h>
using namespace std;

int main()
{
  map<int, string> ms;
  ms[1] = "student_one";
  ms[1] = "student_two";                      //id相同，则覆盖
  ms[2] = "student_three";
  map<int, string>::iterator iter;
  for(iter = ms.begin(); iter != ms.end(); iter++)
    cout<<iter->first<<" "<<iter->second<<endl;
  cout<<endl;
  iter=ms.lower_bound(1);
  cout<<iter->second<<endl;
  iter=ms.upper_bound(1);
  cout<<iter->second<<endl;
  iter = ms.find(1);
  ms.erase(iter);
  for(iter = ms.begin(); iter != ms.end(); iter++)
    cout<<iter->first<<" "<<iter->second<<endl;
  ms.erase(ms.begin(),ms.end());
  cout<<ms.size()<<endl;
  cout<<ms.empty()<<endl;
  return 0;
}

