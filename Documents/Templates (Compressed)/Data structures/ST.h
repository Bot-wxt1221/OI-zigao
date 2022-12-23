#include<cstring>
#include<algorithm>
#define M >
#define mm(a,b)((a)M(b)?(a):(b))
#define ST_DATA_TYPE int
const int ST_MAX_I=1000;const int ST_MAX_J=9;struct ST{ST_DATA_TYPE f[ST_MAX_I][ST_MAX_J];void build(ST_DATA_TYPE*data,int size){memset(f,0,sizeof(f));int k=std::__lg(size);for(register int i=1;i<=size;++i){f[i][0]=data[i];}for(register int j=1;j<=k;++j){for(register int i=1;i<=size-(1<<j)+1;++i){f[i][j]=mm(f[i][j-1],f[i+(1<<(j-1))][j-1]);}}return;}ST_DATA_TYPE query(int l,int r){int k=std::__lg(r-l+1);return mm(f[l][k],f[r-(1<<k)+1][k]);}};