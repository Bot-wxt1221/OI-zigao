#include<cstdio>
#include<queue>
#include<algorithm>
std::priority_queue<int> pq,pq2;
int read(){
    int x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();
    while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c&15),c=getchar();
    return f?-x:x;
}

int main(){
    int n=read();
    int w=read();
    register int now;
    for(register int i=1;i<=n;++i){
        now=-read();
        pq2.push(-now);
        if(pq.empty()||(-pq2.top())<pq.top()||pq.size()<std::max((i*w/100),1)){
            pq.push(-pq2.top());
            pq2.pop();
        }
        if(pq.size()>std::max((i*w/100),1)){
            pq2.push(-pq.top());
            pq.pop();
        }
        printf("%d ",-pq.top());
    }
}