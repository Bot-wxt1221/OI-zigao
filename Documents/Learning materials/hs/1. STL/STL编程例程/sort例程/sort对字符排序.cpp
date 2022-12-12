//sort¶Ô×Ö·ûÅÅĞò
#include <bits/stdc++.h>
using namespace std;

int main()
{
  char a[11]="asdfghjklk";
  for(int i=0; i<10; i++)
    cout<<a[i];
  cout<<endl;
  sort(a,a+10,greater<char>());
  for(int i=0; i<10; i++)
    cout<<a[i];
  cout<<endl;
  return 0;
}

