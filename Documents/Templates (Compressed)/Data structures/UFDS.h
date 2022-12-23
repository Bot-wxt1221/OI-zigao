const int UFDS_SIZE=100;struct UFDS{int parents[UFDS_SIZE];void build(int n){for(register int i=1;i<=n;++i)parents[i]=i;return;}int find(int x){return x==parents[x]?x:(parents[x]=find(parents[x]));}int find_b(int x){while(parents[x]!=x)x=parents[x];return x;}void merge(int i,int j){parents[find(i)]=find(j);return;}void clear(){for(int i=1;i<UFDS_SIZE;i++)parents[i]=i;return;}};