#include<cstdio>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int x[100000+10],d[100000+10],m;

int find(int start,int p){
	register int l=start+1,r=m;
	register int mid,ans=l+1;
	while(l<=r){
		mid=(l+r)>>1;
		if(d[mid]-d[start]>=p){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	return ans;
}

int main(){
	#ifdef file
	freopen("zero1.in", "r", stdin);
//	freopen("zero.out", "w", stdout);
	#endif
	
	register int i=0,di,f;
	const int n=read();
	m=read();
	
	for(i=1;i<=n;++i) x[i]=read();
	
	for(i=1;i<=m;++i) d[i]=read()+d[i-1];
	
	for(i=1;i<=n;++i){
		for(di=0;di<m;){
			if(x[i]>0){
				f=find(di,x[i]);
				x[i]-=d[f]-d[di];
				di=f;
			}else{
				f=find(di,-x[i]);
				x[i]+=d[f]-d[di];
				di=f;
			}
			if(x[i]==0){
				printf("Yes %d\n",di);
				goto loop;
			}
		}
		printf("No %d\n",x[i]);
		loop:;
	}
	

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}

void print(OUTPUT_DATA_TYPE x){
    register char s[20];
    register int i=0;
    if(x<0){
        x=-x;
        putchar('-');
    }
    if(x==0){
        putchar('0');
        return;
    }
    while(x){
        s[i++]=x%10;
        x/=10;
    }
    while(i){
        putchar(s[--i]+'0');
    }
    return;
}
