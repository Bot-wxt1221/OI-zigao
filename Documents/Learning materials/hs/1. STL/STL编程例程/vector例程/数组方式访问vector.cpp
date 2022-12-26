//���鷽ʽ����vector
#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> v;       //������һ�����int���͵�vector����
  v.reserve(30);       //�������ݿռ��С
  v.push_back(20);     //β�˲�����Ԫ��
  v.push_back(26);
  v.push_back(12);
  v.push_back(52);
  v.insert(v.begin(),2);//begin()Ϊvectorͷ��,�ڴ˴�����2
  v.insert(v.end(),43); //end()Ϊvectorβ�����ڴ˴�����43
  v.insert(v.begin()+2,15);              //�ڵ�2��Ԫ��ǰ����15
  v.erase(v.begin()+1);                  //ɾ����2��Ԫ��
  v.erase(v.begin(),v.begin()+2);        //ɾ��ǰ����Ԫ��
  v.pop_back();//ɾ��ĩβ��һ��Ԫ��
  for(int i=0; i<v.size(); ++i)          //size()Ϊv��Ԫ�ظ���
    cout<<v[i]<<' ';
  cout<<"\n ��Ԫ��Ϊ:"<<v.front()<<'\n'; //��Ԫ������
  cout<<"ĩԪ��Ϊ:"<<v.back()<<'\n';     //ĩԪ������
  reverse(v.begin(),v.end());            //��ת����vectorԪ��
  for(int i=0; i<v.size(); ++i)
    cout<<v[i]<<' ';
  v.clear();                             //ȫ�����Ԫ��
  cout<<"\n v�Ƿ�Ϊ��:"<<v.empty()<<'\n';//�ж��Ƿ�Ϊ��
  return 0;
}

