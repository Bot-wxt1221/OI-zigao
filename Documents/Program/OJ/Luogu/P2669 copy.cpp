#include<iostream>
using namespace std;
int main()
{
	int a,b=0,c=1,i;//a为天数，b为金币，c为每天比原来每天多获得的金币数 
	cin>>a;
	for(i=1;i<=a;i++)
		a-=i,b+=c*c,c++;//金币每天加上c的2次方，天数当然要减i了
	cout<<b+a*c;//最后算上剩余的a乘加的最多一次的c
	return 0;
}