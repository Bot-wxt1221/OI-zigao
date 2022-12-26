#include<iostream>

using namespace std;

#define maxN 1000
int r[maxN];

void Sink(int k,int n)//�³�����
{
    while(2*k<=n)//���������
    {
        int j=2*k;//jָ������
        if(j<n&&r[j]<r[j+1])//������Һ��������ӱ��Һ���С
            j++;    //jָ���Һ���
        if(r[k]>=r[j])//�Ƚϴ�ĺ��Ӵ�
            break;    //�������
        else
            swap(r[k],r[j]);//��ϴ�ĺ��ӽ���
        k=j;//kָ�򽻻������λ�ã��������±Ƚϣ�һֱ�³���Ҷ��
    }
}

void Swim(int k)//�ϸ�����
{
    while(k>1&&r[k]>r[k/2])//�������˫��
    {
        swap(r[k],r[k/2]);//��˫�׽���
        k=k/2;//kָ�򽻻������λ�ã��������ϱȽϣ�һֱ�ϸ�����
    }
}

void CreatHeap(int n)//������ʼ��
{
    for(int i=n/2;i>0;i--)//�����һ����֧���n/2��ʼ�³�����Ϊ�ѣ�ֱ����һ�����
        Sink(i,n);
}

void push(int n,int x)//���
{
    r[++n]=x;//n��1�󣬽���Ԫ�ط���β��
    Swim(n);//���һ��Ԫ���ϸ�����
}

void pop(int n)//����
{
    cout<<r[1]<<endl;//����Ѷ�
    r[1]=r[n--];//���һ��Ԫ�ش���Ѷ���n��1
    Sink(1,n);//�Ѷ��³�����
}

int main()
{
    int n,select,x;
    cout << "������������¼������" << endl;
    cin>>n;
    cout<<"������n��������"<<endl;
    for(int i=1;i<=n;i++)
        cin>>r[i];
    CreatHeap(n);//������ʼ��
    while(true)
    {
        cout<<"��ѡ�����֣�1.��ӣ�2.���ӣ�0.�˳�"<<endl;
        cin>>select;
        switch(select)
        {
            case 1:
                cout<<"�������Ԫ�أ�"<<endl;
                cin>>x;
                push(n,x);//���
                break;
            case 2:
                pop(n);//����
                break;
            case 0:
                return 0;
        }
    }
    return 0;
}
