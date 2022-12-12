#include <cstdio>
// #define file

//************************************************************************************************
#include <cstring>
#define BIT_TYPE long long
const int BIT_SIZE=500000+10;
struct BIT{
    BIT_TYPE tree[BIT_SIZE];
    int size;

    void build(BIT_TYPE *data,int datasize){
        size=datasize;
        register BIT_TYPE chafen=0;
        memset(tree,0,sizeof(tree));
        for(register int i=1;i<=datasize;++i){
            tree[i]+=data[i]-chafen;
            tree[i+lowbit(i)]+=tree[i];
            chafen=data[i];
        }
        return;
    }

    BIT_TYPE getsum(int l,int r){
        return presum(r)-presum(l-1);
    }

    BIT_TYPE presum(int pos){
        BIT_TYPE sum=0;
        while(pos){
            sum+=tree[pos];
            pos-=lowbit(pos);
        }
        return sum;
    }

    void add(BIT_TYPE data,int pos){
        while(pos<=size){
            tree[pos]+=data;
            pos+=lowbit(pos);
        }
    }

    BIT_TYPE lowbit(BIT_TYPE x){
        return x&-x;
    }
}bit;
//************************************************************************************************

long long read();
long long arr[BIT_SIZE];

int main(){
	#ifdef file
	freopen("P3368_2.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

    int n=read();
    int m=read();

    for(register int i=1;i<=n;++i) arr[i]=read();

    bit.build(arr,n);

    char op;
    register long long l,r,c;

    for(register int i=1;i<=m;++i){
        op=read();
        if(op==1){
            l=read();
            r=read();
            c=read();
            bit.add(c,l);
            bit.add(-c,r+1);
        }else{
            l=read();
            printf("%lld\n",bit.presum(l));
        }
    }

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

long long read(){
    int x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}