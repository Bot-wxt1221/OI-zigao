//map����3
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <map> 
using namespace std;

int main()
{
  map<int, string> ms;
  ms[1] = "student_one";
  ms[1] = "student_two";//id��ͬ�������
  ms[2] = "student_three";
  pair<map<int,string>::iterator,bool>pa;
  pa=ms.insert(pair<int, string>(2, "student_one"));
  if(!pa.second)//id��ͬ�������ʧ��
    cout<<"error"<<endl;
  ms.insert(pair<int, string>(5, "student_two"));
  ms.insert(pair<int, string>(6, "student_three"));
  map<int, string>::iterator iter;
  for(iter = ms.begin(); iter != ms.end(); iter++)
    cout<<iter->first<<" "<<iter->second<<endl;
  //����ѧ��Ϊ2�ļ�¼����ӡ
  map<int,string>::iterator ii=ms.find(2);
  cout<<"ѧ��Ϊ"<<(*ii).first<<' '<<(*ii).second<<endl;
  return 0;
}

