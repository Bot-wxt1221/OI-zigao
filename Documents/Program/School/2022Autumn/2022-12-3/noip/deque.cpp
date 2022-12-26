#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

struct node{
    int data,i;
}a[2010];

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int max[200010],min[200010];

bool cmp(node a,node b){
    if(a.data!=b.data) return a.data<b.data;
    return a.i<b.i;
}

int main(){
	#ifdef file
	freopen("deque.in", "r", stdin);
	freopen("deque.out", "w", stdout);
	#endif

    register int i,ans=1,_max,_min=1,now_max=-0x3f3f3f3f,now_min=0x3f3f3f3f;
    register char now=0;
    int cnt=1;
    int n=read();
    for(i=1;i<=n;++i) a[i].data=read(),a[i].i=i;

    std::sort(a+1,a+n+1,cmp);

    min[1]=a[1].data;

    for(i=1;i<=n;++i){
        if(a[i].data!=a[i+1].data){
            _max=i;
            if(now==0){
                if(a[_max].i<=now_min){
                    now_min=a[_min].i;
                }else{
                    now=~now;
                    now_max=a[_max].i;
                }
            }else{
                if(a[_min].i<now_max){
                    ans++;
                    now=~now;
                    now_min=a[_min].i;
                }else{
                    now_max=a[_max].i;
                }
            }
            _min=i+1;
        }
    }

    printf("%d",ans);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||'9'<c)f=(c=='-'),c=getchar();//?=if,:=else
    while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
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