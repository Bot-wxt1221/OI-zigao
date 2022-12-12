#include <cstdio>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

#define STACK_DATA_TYPE int
const int STACK_SIZE = 100010;
struct stack{
	STACK_DATA_TYPE _null,s[STACK_SIZE];
	int s_top;

	stack(){
		s_top=0;
		return;
	}

	void push(STACK_DATA_TYPE in){
		s[s_top] = in;
		++s_top;
		return;
	}

	void pop(){
		--s_top;
		return;
	}

	void pop(int in){
		s_top-=in;
		return;
	}

	STACK_DATA_TYPE top(){
		return s[s_top-1];
	}

	void clear(){
		s_top=0;
	}

	bool empty(){
		if(s_top==0){
			return true;
		}else{
			return false;
		}
	}

	int size(){
		return s_top;
	}

	STACK_DATA_TYPE read(int in){
		return s[in];
	}
}S;

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

char book[100010];

int main(){
    register int n,c,l,r,now,best,best_l,best_r,a;
    int T=read();

    while(--T){
        best=-0x3f3f3f3f;
        n=read();
        l=1;
        c=0;
        while(!S.empty()){book[S.top()]=0;S.pop();}
        for(r=1;r<=n;++r){
            a=read();
            if(!book[a]){
                S.push(a);
                book[a]=1;
                ++c;
            }
            if(r-l-c>=(-1))
                now=r-l-c;
            else{
                l=r;
                c=1;
                while(!S.empty()){book[S.top()]=0;S.pop();}
                S.push(a);
                book[a]=1;
            }
            if(now>best){
                best=r-l-c;
                best_l=l;
                best_r=r;
            }
        }
        printf("%d %d\n",best_l,best_r);
    }

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