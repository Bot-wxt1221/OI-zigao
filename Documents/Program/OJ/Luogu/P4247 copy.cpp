#include<bits/stdc++.h>
#define ln q << 1
#define rn (q << 1) | 1
#define lson ln,l,mid
#define rson rn,mid + 1,r
#define md int mid = l + r >> 1
#define lint long long
using namespace std;
const int mo = 19940417;
int n,m;
int zuhe[50010][21];
struct node{
	lint c[21],tagadd;
	int sz;
	bool c2;
	node(){tagadd = sz = c2 = 0;memset(c,0,sizeof(c));}
}t[200010];
int a[50010];
lint tmp[21];
int read(){
	int x = 0,y = 1;
	char c;
	c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') y = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	return x * y;
}
void print(lint q){
	if(q >= 10) print(q / 10);
	putchar(q % 10 + '0');
}
void upd(int q){//向上更新节点 
	register int i,j;
	memset(t[q].c,0,sizeof(t[q].c));
	for(i = 0;i <= 20 && i <= t[ln].sz;++i){
		for(j = 0;j + i <= 20 && j <= t[rn].sz;++j){
			t[q].c[i + j] += t[ln].c[i] * t[rn].c[j];
		}
	}
	for(i = 0;i <= 20 && i <= t[q].sz;++i) t[q].c[i] %= mo;
}
void build(int q,int l,int r){//初始化 
	t[q].sz = r - l + 1;
	if(l == r) {
		t[q].c[0] = 1;
		t[q].c[1] = (a[l] % mo + mo) % mo; 
		return;
	}
	md;
	build(lson);
	build(rson);
	upd(q);
}
void add(int q,int x){//区间加的更新 
	if(!q || !x) return;
	register int i,j;
	tmp[0] = 1;
	for(i = 1;i <= 20 && i <= t[q].sz;++i) tmp[i] = tmp[i - 1] * x % mo;
	for(i = min(20,t[q].sz);i;--i){
		for(j = 0;j < i;++j){
			t[q].c[i] = (t[q].c[i] + t[q].c[j] * tmp[i - j] % mo * zuhe[t[q].sz - j][i - j]) % mo;
		}
	}
	t[q].tagadd = (t[q].tagadd + x) % mo;
}
void rev(int q){//区间取反的更新 
	if(!q) return;
	for(int i = 1;i <= 20 && i <= t[q].sz;++i) t[q].c[i] = (i & 1) ? mo - t[q].c[i] : t[q].c[i];
	t[q].tagadd = mo - t[q].tagadd;
	t[q].c2 ^= 1;
}
void psc(int q){//下传标记 
	if(t[q].c2){
		rev(ln);
		rev(rn);
		t[q].c2 = 0;
	}
	if(t[q].tagadd){
		add(ln,t[q].tagadd);
		add(rn,t[q].tagadd);
		t[q].tagadd = 0;
	}
}
void md1(int q,int l,int r,int al,int ar,int ax){//区间加 
	if(l >= al && r <= ar){
		add(q,ax);
		return;
	}
	psc(q);
	md;
	if(mid >= al) md1(lson,al,ar,ax);
	if(mid < ar) md1(rson,al,ar,ax);
	upd(q);
}
void md2(int q,int l,int r,int al,int ar){//区间取反 
	if(l >= al && r <= ar) {
		rev(q);
		return;
	}
	psc(q);
	md;
	if(mid >= al) md2(lson,al,ar);
	if(mid < ar) md2(rson,al,ar);
	upd(q);
}
node mg(node q,node w){//合并两段区间 
	node e;
	register int i,j;
	e.sz = q.sz + w.sz;
	for(i = 0;i <= 20 && i <= q.sz;++i){
		for(j = 0;j + i <= 20 && j <= w.sz;++j){
			e.c[i + j] = (e.c[i + j] + q.c[i] * w.c[j]) % mo;
		}
	}
	return e;
}
node query(int q,int l,int r,int al,int ar){//区间查询 
	if(l >= al && r <= ar) return t[q];
	psc(q);
	md;
	if(ar <= mid) return query(lson,al,ar);
	else if(al > mid) return query(rson,al,ar);
	else return mg(query(lson,al,ar),query(rson,al,ar));
}
int main(){
	node temp___;
	int i,j,k,l,r,x;
	char c;
	n = read();
	m = read();
	for(i = 1;i <= n;++i) a[i] = read();
	t[0].c[0] = 1; 
	zuhe[0][0] = 1;
	for(i = 1;i <= n;++i){
		zuhe[i][0] = 1;
		for(j = 1;j <= 20 && j <= i;++j) zuhe[i][j] = (zuhe[i - 1][j] + zuhe[i - 1][j - 1]) % mo;
	}//预处理组合数 
	// build(1,1,n);
	for(i = 1;i <= n;++i){
		c = getchar();
		while(c != 'I' && c != 'Q' && c != 'R') c = getchar();
		l = read();
		r = read();
		if(c == 'I'){
			x = read();
			// x = (x % mo + mo) % mo;
			// md1(1,1,n,l,r,x);
		}else if(c == 'R'){
			// md2(1,1,n,l,r);
		}else{
			x = read();
			// print(((temp___=query(1,1,n,l,r)).c[x] % mo + mo) % mo);
			// putchar('\n');
		}
	}
	return 0;
}
