#include <cstdio>
#include <algorithm>
#define file
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE long long

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

struct node{
	int x,y,w;
	bool operator  < (const node in) const{
		if(in.x!=x) return x<in.x;
		return y<in.y;
	}
}mirrors_x[100000+10],mirrors_y[100000+10];

bool cmp_x(node a,node b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}

bool cmp_y(node a,node b){
	if(a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}

bool b_cmp_x(node a,node b){
	return a.x<b.x;
}

bool b_cmp_y(node a,node b){
	return a.y<b.y;
}

unsigned book[100000+10];

/*
5 2 8
0 1 \
0 2 /
1 0 /
1 1 \
1 2 \
*/

int main(){
	#ifdef file
	freopen("mirror.in", "r", stdin);
	freopen("mirror.out", "w", stdout);
	#endif
	
	register int i;
	register long long up,low,f,T;
	register node t;
	t.x=0;
	t.y=0;
	t.w=0;
	int n=read();
	int m=read();
	T=read();
	
	for(i=1;i<=n;++i){
		mirrors_y[i].x=mirrors_x[i].x=read();
		mirrors_y[i].y=mirrors_x[i].y=read();
		loop:mirrors_y[i].w=mirrors_x[i].w=getchar();
		if(mirrors_y[i].w!='\\'&&mirrors_y[i].w!='/') goto loop;
		mirrors_y[i].w=mirrors_x[i].w=i<<1;
	}
	
	std::sort(mirrors_x,mirrors_x+n,cmp_x);
	std::sort(mirrors_y,mirrors_y+n,cmp_y);
	
	while(true){
		if(t.w==0){
			low=std::lower_bound(mirrors_x+1,mirrors_x+n+1,t,b_cmp_x)-mirrors_x;
			up=std::upper_bound(mirrors_x+1,mirrors_x+n+1,t,b_cmp_x)-mirrors_x-1;
			f=std::lower_bound(mirrors_x+low,mirrors_x+up+1,t,b_cmp_y)-mirrors_x;
			if(mirrors_x[f].x!=t.x||(mirrors_x[f].x-t.x)>=T){
				print(t.x+T);
				print(t.y);
			}else{
				t.x=mirrors_x[f].x;
				T-=mirrors_x[f].x-t.x;
				if(mirrors_x[f].w=='\\')  t.w=3;
				else t.w=1;
			}
		}else if(t.w==1){
			low=std::lower_bound(mirrors_y+1,mirrors_y+n+1,t,b_cmp_y)-mirrors_y;
			up=std::upper_bound(mirrors_y+1,mirrors_y+n+1,t,b_cmp_y)-mirrors_y-1;
			f=std::lower_bound(mirrors_y+low,mirrors_y+up+1,t,b_cmp_x)-mirrors_y;
			if(mirrors_y[f].y!=t.y||(mirrors_y[f].y-t.y)>=T){
				print(t.x);
				print(t.y+T);
			}else{
				t.y=mirrors_y[f].y;
				T-=mirrors_y[f].y-t.y;
				if(mirrors_y[f].w=='\\')  t.w=2;
				else t.w=0;
			}
		}else if(t.w==2){
			low=std::lower_bound(mirrors_x+1,mirrors_x+n+1,t,b_cmp_x)-mirrors_x;
			up=std::upper_bound(mirrors_x+1,mirrors_x+n+1,t,b_cmp_x)-mirrors_x-1;
			f=std::lower_bound(mirrors_x+low,mirrors_x+up+1,t,b_cmp_y)-mirrors_x-1;
			if(mirrors_x[f].x!=t.x||(-mirrors_x[f].x+t.x)>=T){
				print(t.x+T);
				print(t.y);
			}else{
				t.x=mirrors_x[f].x;
				T+=mirrors_x[f].x-t.x;
				if(mirrors_x[f].w=='\\')  t.w=1;
				else t.w=3;
			}
		}else if(t.w==3){
			low=std::lower_bound(mirrors_y+1,mirrors_y+n+1,t,b_cmp_y)-mirrors_y;
			up=std::upper_bound(mirrors_y+1,mirrors_y+n+1,t,b_cmp_y)-mirrors_y-1;
			f=std::lower_bound(mirrors_y+low,mirrors_y+up+1,t,b_cmp_x)-mirrors_y-1;
			if(mirrors_y[f].y!=t.y||(mirrors_y[f].y-t.y)>=T){
				print(t.x);
				print(t.y+T);
			}else{
				t.y=mirrors_y[f].y;
				T+=mirrors_y[f].y-t.y;
				if(mirrors_y[f].w=='\\')  t.w=0;
				else t.w=2;
			}
		}
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
