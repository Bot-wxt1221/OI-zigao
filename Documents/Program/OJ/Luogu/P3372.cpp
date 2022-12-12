#include <cstdio>
//#define file

//************************************************************************************************
#define SEQ_TYPE long long
const int SEQ_SIZE=1000000+10;
struct node{
    SEQ_TYPE t;
    SEQ_TYPE data;
    node(){
        t=0;
        return;
    }
};

struct seq{
    node tree[SEQ_SIZE<<2];
    void build(int l,int r,int p,SEQ_TYPE *data){
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

    SEQ_TYPE getsum(int &l,int &r,int s,int t,int p){
        if(l<=s&&t<=r) return tree[p].data;
        int mid=s+((t-s)>>1);
        SEQ_TYPE sum=0;
        if(tree[p].t){
            tree[p<<1].data+=(mid-s+1)*tree[p].t;
            tree[(p<<1)+1].data+=(t-mid)*tree[p].t;
            tree[p<<1].t+=tree[p].t;
            tree[(p<<1)+1].t+=tree[p].t;
            tree[p].t=0;
        }
        if(l<=mid) sum+=getsum(l,r,s,mid,p<<1);
        if(r>mid) sum+=getsum(l,r,mid+1,t,(p<<1)+1);
        return sum;
    }

    void update(int &l,int &r,int s,int t,int &c,int p){
        if(l<=s&&t<=r){
            tree[p].data+=(t-s+1)*c,tree[p].t+=c;
            return;
        }
        int mid=s+((t-s)>>1),sum=0;
        if(tree[p].t){
            tree[p<<1].data+=(mid-s+1)*tree[p].t;
            tree[(p<<1)+1].data+=(t-mid)*tree[p].t;
            tree[p<<1].t+=tree[p].t;
            tree[(p<<1)+1].t+=tree[p].t;
            tree[p].t=0;
        }
        if(l<=mid) update(l,r,s,mid,c,p<<1);
        if(r>mid) update(l,r,mid+1,t,c,(p<<1)+1);
        tree[p].data=tree[p<<1].data+tree[(p<<1)+1].data;
    }
}seq;
//************************************************************************************************

long long read();
long long arr[SEQ_SIZE];

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

    int n=read();
    int m=read();

    for(register int i=1;i<=n;++i) arr[i]=read();

    seq.build(1,n,1,arr);

    char op;
    register int l,r,c;

    for(register int i=1;i<=m;++i){
        op=read();
        if(op==1){
            l=read();
            r=read();
            c=read();
            seq.update(l,r,1,n,c,1);
        }else{
            l=read();
            r=read();
            printf("%lld\n",seq.getsum(l,r,1,n,1));
        }
    }

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

long long read(){
    long long x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}