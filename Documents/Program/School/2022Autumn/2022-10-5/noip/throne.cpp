#include <cstdio>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

struct node{
	char sex;
	int s;
}nodes[15000000+10];

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);
int calc(int x,register int l,int r){
	register int ans=0;
	for(;l<=r;l+=nodes[l].s+1)
		if(nodes[l].sex^nodes[x].sex) ans+=nodes[l].s+1;
	return ans;
}

int main(){
	#ifdef file
	freopen("throne.in", "r", stdin);
	freopen("throne.out", "w", stdout);
	#endif
	
	register int i,pre,ans;
	int n=read();
	int m=read();
	
	for(i=0;i<n;++i){
		nodes[i].s=read();
		nodes[i].sex=read();
	}
	
	ans=0;
	
	for(i=1,pre=0;i<n;)
		if(i==m){
			if(nodes[i].sex==0)
				ans+=calc(i,i,pre+nodes[pre].s);
			else ans-=calc(i,pre+1,i-1);
			break;
		}else if(i<m&&m<=i+nodes[i].s){
			if(nodes[i].sex==0)
				ans+=calc(i,i,pre+nodes[pre].s);
			else ans-=calc(i,pre+1,i-1);
			pre=i,i++;
		}else{
			i+=nodes[i].s+1;
		}
		
	print(ans);

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
