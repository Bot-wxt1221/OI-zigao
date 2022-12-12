//×Ö·ûÕ»
#include <bits/stdc++.h>
using namespace std;

int main()
{
  stack <char> st;
  for(char i='a'; i<='z';)
  {
    st.push(i++);
    st.push(i++);
    st.pop();
  }
  while(!st.empty())
  {
    cout<<st.top()<<" ";
    st.pop();
  }
  return 0;
}

