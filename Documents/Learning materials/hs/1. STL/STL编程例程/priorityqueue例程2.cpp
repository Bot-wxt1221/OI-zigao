
/*���ȶ��еĻ���ʹ��  */
#include<iostream>
#include<functional>
#include<queue>
#include<vector>
using namespace std;
//�Զ������ȼ�1����ֵ����
struct cmp1{
    bool operator ()(int &a,int &b){
        return a<b;//���ֵ����
    }
};
struct cmp2{
    bool operator ()(int &a,int &b){
        return a>b;//��Сֵ����
    }
};
//�Զ������ȼ�2,�ṹ������
struct node1{
    int x,y;//�ṹ���еĳ�Ա
    node1() {}//Ϊ���㸳ֵ�����ù��캯��
    node1(int _x,int _y)
    {
        x = _x;
        y = _y;
    };
    bool operator < (const node1 &a) const {
        return x<a.x;//����Աx���ֵ����
    }
};
struct node2{
    int x,y;//�ṹ���еĳ�Ա
    node2() {}
    node2(int _x,int _y)
    {
        x = _x;
        y = _y;
    };
    bool operator < (const node2 &a) const {
        return x>a.x;//����Աx��Сֵ����
    }
};

//�Զ������ȼ�3,�ṹ������
struct node3{
    int x,y;  //�ṹ���еĳ�Ա
    node3() {}
    node3(int _x,int _y)
    {
        x = _x;
        y = _y;
    };
};
bool operator <(const node3 &a, const node3 &b)//���ȼ������ڽṹ������
{
  return a.x<b.x; //����Աx���ֵ����
}

struct node4{
    int x,y;  //�ṹ���еĳ�Ա
    node4() {}
    node4(int _x,int _y)
    {
        x = _x;
        y = _y;
    };
};
bool operator <(const node4 &a, const node4 &b)
{
   return a.y>b.y; //����Աy��Сֵ����
}

int a[]={15,7,32,26,97,48,36,89,6,49,67,0};
int b[]={1,2,5,6,9,8,6,9,7,19,27,0};

int main()
{   priority_queue<int>que;//����Ĭ�����ȼ��������

    //ʹ��C++�Դ��Ŀ⺯��<functional>��
    priority_queue<int,vector<int>,less<int> >que1;//���ֵ����,ע�⡰>>���ᱻ��Ϊ����������������������������ÿո�Ÿ���
    priority_queue<int,vector<int>,greater<int> >que2;  //��Сֵ����

    //�Զ������ȼ�1
    priority_queue<int,vector<int>,cmp1>que3;
    priority_queue<int,vector<int>,cmp2>que4;

   //�Զ������ȼ�2
    priority_queue<node1>que5;
    priority_queue<node2>que6;

    //�Զ������ȼ�3
    priority_queue<node3>que7;
    priority_queue<node4>que8;

    int i;
    for(i=0;a[i];i++)
    {//a[i]Ϊ0ʱֹͣ���������һ����Ϊ0
        que.push(a[i]);
        que1.push(a[i]);
        que2.push(a[i]);
        que3.push(a[i]);
        que4.push(a[i]);
    }
     for(i=0;a[i]&&b[i];i++)
    {//a[i]��b[i]Ϊ0ʱֹͣ���������һ����Ϊ0
        que5.push(node1(a[i],b[i]));
        que6.push(node2(a[i],b[i]));
        que7.push(node3(a[i],b[i]));
        que8.push(node4(a[i],b[i]));
    }

    cout<<"����Ĭ�����ȼ�:"<<endl;
    cout<<"Queue 0:"<<endl;
    while(!que.empty()){
        cout<<que.top()<<"  ";
        que.pop();
    }
    cout<<endl;
    cout<<endl;

    cout<<"����ͷ�ļ�\"functional\"�ڶ������ȼ�:"<<endl;
    cout<<"Queue 1:"<<endl;
    while(!que1.empty()){
        cout<<que1.top()<<"  ";
        que1.pop();
    }
    cout<<endl;
    cout<<"Queue 2:"<<endl;
    while(!que2.empty()){
        cout<<que2.top()<<"  ";
        que2.pop();
    }
    cout<<endl;
    cout<<endl;

    cout<<"�����Զ������ȼ���ʽ1:"<<endl;
    cout<<"Queue 3:"<<endl;
    while(!que3.empty()){
        cout<<que3.top()<<"  ";
        que3.pop();
    }
    cout<<endl;
    cout<<"Queue 4:"<<endl;
    while(!que4.empty()){
        cout<<que4.top()<<"  ";
        que4.pop();
    }
    cout<<endl;
    cout<<endl;

    cout<<"�����Զ������ȼ���ʽ2:"<<endl;
    cout<<"Queue 5:"<<endl;
    while(!que5.empty()){
        cout<<que5.top().x<<"  ";
        que5.pop();
    }
    cout<<endl;
    cout<<"Queue 6:"<<endl;
    while(!que6.empty()){
        cout<<que6.top().x<<"  ";
        que6.pop();
    }
    cout<<endl;
    cout<<endl;

    cout<<"�����Զ������ȼ���ʽ3:"<<endl;
    cout<<"Queue 7:"<<endl;
    while(!que7.empty()){
        cout<<que7.top().x<<"  ";
        que7.pop();
    }
    cout<<endl;
    cout<<"Queue 8:"<<endl;
    while(!que8.empty()){
        cout<<que8.top().y<<"  ";
        que8.pop();
    }
    cout<<endl;
    return 0;
}
