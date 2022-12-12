#include <cstdio>
#include <set>
#include <algorithm>
#define file

//************************************************************************************************
#define SEQ_DATA_TYPE int
const int SEQ_SIZE=200000+10;

int read();
int arr[SEQ_SIZE],n;

struct NODE{
    SEQ_DATA_TYPE data;
};

struct SEQ{
    NODE tree[SEQ_SIZE<<2];

    void build(int l,int r,int p){
        if(l==r){
            tree[p].data=1;
            return;
        }
        int mid=l+((r-l)>>1);
        build(l,mid,p<<1);
        build(mid+1,r,(p<<1)+1);
        tree[p].data=tree[p<<1].data+tree[(p<<1)+1].data;
        return;
    }

    int find(register int k){
    	register int p=1,l=1,r=n;
    	while(l!=r){
    		if(tree[p<<1].data>=k){
    			r=(l+r)>>1;
    			p<<=1;
    		}else{
    			k-=tree[p<<1].data;
    			l=((l+r)>>1)+1;
    			p=(p<<1)+1;
    		}
    	}
		return l;
    }
    
    void add(int pos,int s,int t,int p,int c){
    	if(s==t&&s==pos){
    		--tree[p].data;
    		return;
    	}
        int mid=s+((t-s)>>1);
        if(pos<=mid) add(pos,s,mid,p<<1,c);
        if(mid<pos) add(pos,mid+1,t,(p<<1)+1,c);
        tree[p].data=tree[p<<1].data+tree[(p<<1)+1].data;
        return;
    }
}seq;
//************************************************************************************************


int main(){
	#ifdef file
	freopen("flandre.in", "r", stdin);
	freopen("flandre.out", "w", stdout);
	#endif

	n=read();
	register int i,k,t;
	for(i=1;i<=n;++i){
//		arr[i]=read();
		scanf("%d",arr+i);
	}
	
	seq.build(1,n,1);
	std::sort(arr+1,arr+1+n);
	
	for(i=0;i<n;++i){
		k=read();
		t=seq.find(k);
		printf("%d\n",arr[t]);
		seq.add(t,1,n,1,1);
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
