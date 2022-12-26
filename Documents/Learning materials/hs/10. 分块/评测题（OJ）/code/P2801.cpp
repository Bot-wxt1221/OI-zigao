#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000005, SQ = 1005; 
int st[SQ], ed[SQ], size[SQ], bel[MAXN]; 

void init_block(int n) // ��ʼ��
{ 
	int sq = sqrt(n); 
	for (int i = 1; i <= sq; ++i) 
	{ 
		st[i] = n / sq * (i - 1) + 1; 
		ed[i] = n / sq * i; 
	} 
	ed[sq] = n; 
	for (int i = 1; i <= sq; ++i) 
		for (int j = st[i]; j <= ed[i]; ++j) 
			bel[j] = i; 
	for (int i = 1; i <= sq; ++i) 
		size[i] = ed[i] - st[i] + 1; 
} 

int A[MAXN], mark[SQ]; 
vector<int> v[SQ]; // ������vector������������
void update(int b) // ��������������
{ 
	for (int i = 0; i <= size[b]; ++i)
	v[b][i] = A[st[b] + i]; 
	sort(v[b].begin(), v[b].end()); 
} 

int main() 
{ 
	int n = read(), m = read(); 
	int sq = sqrt(n); 
	init_block(n); 
	for (int i = 1; i <= n; ++i) 
		A[i] = read();
	for (int i = 1; i <= sq; ++i) 
		for (int j = st[i]; j <= ed[i]; ++j) 
			v[i].push_back(A[j]); 
	for (int i = 1; i <= sq; ++i) 
		sort(v[i].begin(), v[i].end()); 
	while (m--) 
	{ 
		char o; 
		scanf(" %c", &o); 
		int l = read(), r = read(), k = read(); 
		if (o == 'M') 
		{ 
			if (bel[l] == bel[r]) // ���ͬ��һ��ֱ�ӱ���
			{ 
				for (int i = l; i <= r; ++i) 
					A[i] += k; 
				update(bel[l]); 
				continue; 
			} 
			for (int i = l; i <= ed[bel[l]]; ++i) // ����ɢ�鱩������
				A[i] += k; 
			for (int i = st[bel[r]]; i <= r; ++i) 
				A[i] += k; 
			update(bel[l]); 
			update(bel[r]); 
			for (int i = bel[l] + 1; i < bel[r]; ++i) // ���ϱ��
				mark[i] += k; 
			} 
		else
		{ 
			int tot = 0; 
			if (bel[l] == bel[r]) 
			{ 
				for (int i = l; i <= r; ++i) 
					if (A[i] + mark[bel[l]] >= k) 
						tot++; 
				printf("%d\n", tot); 
				continue; 
			} 
			for (int i = l; i <= ed[bel[l]]; ++i) 
				if (A[i] + mark[bel[l]] >= k) 
					tot++; 
			for (int i = st[bel[r]]; i <= r; ++i) 
				if (A[i] + mark[bel[r]] >= k) 
					tot++;
			// ���ֲ���k-mark[i]��λ�ã���Ϊ���鶼������mark[i]��ʵ���൱��k��ȥmark[i] 
			for (int i = bel[l] + 1; i < bel[r]; ++i) 
				tot += v[i].end() - lower_bound(v[i].begin(), v[i].end(), k - mark[i]);
			printf("%d\n", tot); 
		} 
	} 
	return 0; 
}
