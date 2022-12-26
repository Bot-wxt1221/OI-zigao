#include<cstdio>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}
#define QUEUE_TYPE int
const int QUEUE_SIZE=2000010;struct QUEUE{QUEUE_TYPE q[QUEUE_SIZE];int head,tail;QUEUE(){head=0;tail=-1;return;}void push(QUEUE_TYPE in){q[++tail]=in;return;}void pop(){head=head+1;return;}void pop_back(){tail=tail-1;return;}QUEUE_TYPE front(){return q[head];}QUEUE_TYPE back(){return q[tail];}void clear(){head=0;tail=-1;return;}bool empty(){if(tail+1==head)return true;else return false;}int size(){return tail-head+1;}QUEUE_TYPE read(int in){return q[head+in];}};

QUEUE Q_data,Q_index;


int main(){
    register int i,now;
    int n=read();
    int m=read();
    for(i=0;i<n;++i){
        now=read();
        while(Q_data.size()&&i-Q_index.front()>m) Q_data.pop(),Q_index.pop();
        print(Q_data.front());
        putchar('\n');
        while(Q_data.size()&&now<Q_data.back()) Q_data.pop_back(),Q_index.pop_back();
        Q_data.push(now);
        Q_index.push(i);
    }

    return 0;
}