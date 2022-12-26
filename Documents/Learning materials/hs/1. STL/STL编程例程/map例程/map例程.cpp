//map����2
#include<bits/stdc++.h>
using namespace std;

int main()
{
  map<int, string> ms;
  ms[1] = "student_one";
  ms[1] = "student_two";        //id��ͬ���򸲸�
  ms[2] = "student_three";
  map<int, string>::iterator iter;
  ms.insert(make_pair(3,"student_four"));//������Ԫ��
  for(iter = ms.begin(); iter != ms.end(); iter++)
    cout<<iter->first<<" "<<iter->second<<endl;
  cout<<endl;
  iter=ms.lower_bound(1);       //�׸����ڵ���1��Ԫ��
  cout<<iter->second<<endl;
  iter=ms.upper_bound(1);       //�׸�����1��Ԫ��
  cout<<iter->second<<endl;
  iter = ms.find(1);            //���Ҽ�ֵΪ1��Ԫ��λ��
  ms.erase(iter);               //ɾ����ֵΪ1��Ԫ��
  for(iter = ms.begin(); iter != ms.end(); iter++)
    cout<<iter->first<<" "<<iter->second<<endl;
  ms.erase(ms.begin(),ms.end());//ɾ��ȫ��Ԫ��
  cout<<ms.size()<<endl;
  cout<<ms.empty()<<endl;       //empty()�ж�map�Ƿ�Ϊ��
  return 0;
}

