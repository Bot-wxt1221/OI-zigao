#include<iostream>
#include<algorithm>
using namespace std;
struct student{	
    int id,y,s,e,sc; 
}stu[300];

int cmp(const student &a,const student &b){
	if(a.sc>b.sc)return 1;
	else if(a.sc==b.sc)
		 if(a.y>b.y)return 1;else return 0;
	else return 0;
}

int main() {
	int n;cin>>n;
	for(int i=0;i<n;i++){
		stu[i].id=i+1;cin>>stu[i].y>>stu[i].s>>stu[i].e;
		stu[i].sc=stu[i].y+stu[i].s+stu[i].e;
	}
	stable_sort(stu,stu+n,cmp);//��ѧ�����гɼ���������
	for(int i=0;i<5;i++)cout<<stu[i].id<<" "<<stu[i].sc<<endl; 
	return 0;
}
