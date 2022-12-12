#include <cstdio>
// #define file

//************************************************************************************************
#include <cstring>
#define BIT_DATA_TYPE int
const int BIT_SIZE=500000+10;
struct BIT{
    BIT_DATA_TYPE tree[BIT_SIZE];
    int size;

    void build(BIT_DATA_TYPE *data,int datasize){
        size=datasize;
        for(register int i=1;i<=datasize;++i){
            tree[i]+=data[i];
            tree[i+lowbit(i)]+=tree[i];
        }
        return;
    }

    BIT_DATA_TYPE getsum(int l,int r){
        return presum(r)-presum(l-1);
    }

    BIT_DATA_TYPE presum(int pos){
        BIT_DATA_TYPE sum=0;
        while(pos){
            sum+=tree[pos];
            pos-=lowbit(pos);
        }
        return sum;
    }

    void add(BIT_DATA_TYPE data,int pos){
        while(pos<=size){
            tree[pos]+=data;
            pos+=lowbit(pos);
        }
    }

    BIT_DATA_TYPE lowbit(BIT_DATA_TYPE x){
        return x&-x;
    }

    void clear(){
        memset(this,0,sizeof(BIT));
        return;
    }
}bit;
//************************************************************************************************

int read();
int arr[BIT_SIZE];

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

    int n=read();
    int m=read();

    for(register int i=1;i<=n;++i) arr[i]=read();

    bit.build(arr,n);

    char op;
    register int l,r,c;

    for(register int i=1;i<=m;++i){
        op=read();
        if(op==1){
            l=read();
            c=read();
            bit.add(c,l);
        }else{
            l=read();
            r=read();
            printf("%d\n",bit.getsum(l,r));
        }
    }

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

int read(){
    int x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}