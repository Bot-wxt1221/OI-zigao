#include<cstdio>
#define file
//#define int long long

//************************************************************************************************
#define SEQ_DATA_TYPE long long
const int SEQ_SIZE=1000000+10;
struct NODE{
    SEQ_DATA_TYPE add;
    SEQ_DATA_TYPE data;
    NODE(){
        add=0;
        return;
    }
};

struct SEQ{
    NODE tree[SEQ_SIZE<<2];

    void build(int l,int r,int p,SEQ_DATA_TYPE *data){
        if(l==r){
            tree[p].data=data[l];
            return;
        }
        int mid=l+((r-l)>>1);
        build(l,mid,p<<1,data);
        build(mid+1,r,(p<<1)+1,data);
        tree[p].data=tree[p<<1].data+tree[(p<<1)+1].data;
        return;
    }

    SEQ_DATA_TYPE getsum(int l,int r,int s,int t,int p){
        if(l<=s&&t<=r) return tree[p].data;
        int mid=s+((t-s)>>1);
        push_down(p,s,t,mid);
        return ((l<=mid)?getsum(l,r,s,mid,p<<1):0)+((mid<r)?getsum(l,r,mid+1,t,(p<<1)+1):0);
    }

    void add(int l,int r,int s,int t,int p,SEQ_DATA_TYPE c){
        if(l<=s&&t<=r){
            tree[p].data+=(t-s+1)*c,tree[p].add+=c;
            return;
        }
        int mid=s+((t-s)>>1);
        push_down(p,s,t,mid);
        if(l<=mid) add(l,r,s,mid,p<<1,c);
        if(mid<r) add(l,r,mid+1,t,(p<<1)+1,c);
        tree[p].data=tree[p<<1].data+tree[(p<<1)+1].data;
        return;
    }

    void push_down(int p,int l,int r,int mid){
        tree[p<<1].data+=tree[p].add*(mid-l+1);
        tree[(p<<1)+1].data+=tree[p].add*(r-mid);
        tree[p<<1].add+=tree[p].add;
        tree[(p<<1)+1].add+=tree[p].add;
        tree[p].add=0;
        return;
    }
}seq;
//************************************************************************************************

long long read();
long long arr[SEQ_SIZE];

signed main(){
	#ifdef file
	freopen("segment_tree25.in", "r", stdin);
	freopen("segment_tree2.out", "w", stdout);
	#endif

    int n=read();
    int m=read();

    for(register int i=1;i<=n;++i) arr[i]=read() ; 

    seq.build(1,n,1,arr);

    char op;
    long long l,r,c;

    for(register int i=1;i<=m;++i){
        op=read();
        if(op==1){
            l=read();
            r=read();
            c=read();
            seq.add(l,r,1,n,1,c);
        }else{
            l=read();
            r=read();
            printf("%lld\n",seq.getsum(l,r,1,n,1));
        }
    }

//printf("%d",read());

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

long long read(){
    long long x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c&15),c=getchar();
    return f?-x:x;
}
