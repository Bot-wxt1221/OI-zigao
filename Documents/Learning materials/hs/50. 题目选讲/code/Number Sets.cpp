typedef long long LL;

int prime[1000000];   //������1000000�ĵ� i ��������
int p;                //�����ĸ���

//����
LL A, B, P;

void solve() {
	int len = B - A + 1;
	init_union_find(len);    //��ʼ�����鼯
	
	for (int i = 0; i < p; i++) {
		//�Բ�С�� P ���������д���
		if (prime[i] >= P) {
			//��С��A����С��prime[i]�ı���
			LL start = (A + prime[i] - 1) / prime[i] * prime[i];
			//������B������prime[i]�ı��� 
			LL end =  B / prime[i] * prime[i];
			
			for (LL j = start; j <= end; j += prime[i]) {
				//start�� j ����ͬһ������
				unite(start - A, j - A); 
			}
		} 
	} 
	int res = 0;
	for (LL i = A; i <= B; i++) {
		//find[i] == iʱ��i���ǲ��鼯�ĸ�
		//���ϵĸ������ڸ��ĸ���
		if(find(i - A) == i -A) res++; 
	}
	printf("%d\n", res);
} 
