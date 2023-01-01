#include<cstdio>
#include<algorithm>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}
#define QUEUE_TYPE int
const int QUEUE_SIZE=200010;struct QUEUE{QUEUE_TYPE q[QUEUE_SIZE];int head,tail;QUEUE(){head=0;tail=-1;return;}void push(QUEUE_TYPE in){q[++tail]=in;return;}void pop(){head=head+1;return;}void pop_back(){tail=tail-1;return;}QUEUE_TYPE front(){return q[head];}QUEUE_TYPE back(){return q[tail];}void clear(){head=0;tail=-1;return;}bool empty(){if(tail+1==head)return true;else return false;}int size(){return tail-head+1;}QUEUE_TYPE read(int in){return q[head+in];}};

long long dp[200010];
QUEUE q;

int main(){
    register int i;
    register int long long now;
    int n=read();
    int l=read();
    int r=read();
    for(i=0;i<=n;++i){
        now=read();
        if(!i) dp[i]=now;
        else if(i<l) dp[i]=-0x7ffffffff;
        else{
            while(q.size()&&i>q.front()+r) q.pop();
            while(q.size()&&dp[i-l]>dp[q.back()]) q.pop_back();
            q.push(i-l);
            dp[i]=dp[q.front()]+now;
        }
    }
    r=dp[n];
    for(i=std::max(n-r+1,0);i<n;++i)
        if(dp[i]>r) r=dp[i];
    print(r);

    return 0;
}