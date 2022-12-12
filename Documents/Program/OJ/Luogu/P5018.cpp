#include <cstdio>
#include <queue>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
#define MAXN (200000+10)

std::queue <int>qarr[MAXN];
int next[MAXN],n,j;

INPUT_DATA_TYPE read();
void print(int x);

int getnext(int x){
    if(x<=j){
        if(qarr[x].empty()){
            return next[x]=getnext(next[x]);
        }else{
            return x;
        }
    }
    return x;
}

int main(){
    n=read();
    register int cnt;
    register int last,now=-1;
    for(register int i=1;i<=n;++i){
        last=now;
        now=read();
        if(now==last){
            qarr[j].push(i);
        }else{
            next[j]=j+1;
            qarr[++j].push(i);
        }
    }
    cnt=n;
    for(register int i=0;i<MAXN;++i){
        next[i]=i+1;
    }
    while(cnt){
        last=0;
        now=1;
        while(now<=j){
            if((!qarr[now].empty())&&(((now-last)&1)||last==1)){
                print(qarr[now].front());
                qarr[now].pop();
                --cnt;
                putchar(' ');
            }
            last=now;
            now=next[now]=getnext(next[now]);
        }
        putchar('\n');
    }

    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}

void print(OUTPUT_DATA_TYPE x){
    char s[20];
    register int i=0;
    if(x<0){
        x=-x;
        putchar('-');
    }
    while(x){
        s[i++]=x%10;
        x/=10;
    }
    while(i){
        putchar(s[--i]+'0');
    }
}