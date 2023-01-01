/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include<cstdio>
#include<cmath>
#include<cstring>
//#define file
using namespace std;

const int MAX_SIZE=1000+10;
struct UFDS{
	int parents[MAX_SIZE];

	UFDS(){
		for(register int i=0;i<MAX_SIZE;++i)
			parents[i]=i;
		return;
	}

	int find(int x){
		return x==parents[x]?x:(parents[x]=find(parents[x]));
	}

	int find_b(int x){
		while(parents[x]!=x)
			x=parents[x];
		return x;
	}

	void merge(int i,int j){
		parents[find(i)]=find(j);
		return;
	}

	void clear(){
		for(int i=0;i<MAX_SIZE;i++)
			parents[i]=i;
		return;
	}
}u;

struct node{
    int x,y,z;
}arr[1000+10];

int T,n,h,r;

bool check(node a,node b){
    long long x1=a.x;
    long long x2=b.x;
    long long y1=a.y;
    long long y2=b.y;
    long long z1=a.z;
    long long z2=b.z;
    double R=r<<1;
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))-R<=0;
}

int read();

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

    T=read();

    while(T--){
        memset(arr,0,sizeof(arr));
        u.clear();
        n=read();
        h=read();
        r=read();

        for(register int i=0;i<n;++i){
            arr[i].x=read();
            arr[i].y=read();
            arr[i].z=read();
            for(register int j=0;j<i;++j)
                if(check(arr[i],arr[j])) u.merge(i,j);
            if(arr[i].z<=r) u.merge(i,n);
            if(arr[i].z+r>=h) u.merge(i,n+1);
        }

        if(u.find(n)==u.find(n+1)) printf("Yes");
        else printf("No");
        putchar('\n');
    }

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
