//����
int P;
int a[MAX_P];

void solve() {
	//����ȫ��֪ʶ�������
	
	set<int> all;
	for (int i = 0; i < P; i++) {
		all.insert(a[i]);
	} 
	int n = all.size();
	
	//���û�������˼�������
	int s = 0, t = 0, num = 0;
	map<int,int> count;   //֪ʶ��-->���ִ�����ӳ��
	int res = P;
	for (;;) {
		while (t < P && num < n) {
			if (count[a[t++]]++ == 0) {
				//�����µ�֪ʶ��
				num++; 
			}
		} 
		if (num < n) break;
		res = min(res, t - s);
		if(--count[a[s++]] == 0) {
			//ĳ��֪ʶ��ĳ��ִ���Ϊ 0��
			num--; 
		}
	} 
	 
	printf("%d\n", res);
} 
