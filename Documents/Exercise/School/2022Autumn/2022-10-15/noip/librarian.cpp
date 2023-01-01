#include<cstdio>
#include<algorithm>
// #define file

int arr[1001];
//int mod[1001];

int read();

int main(){
	#ifdef file
	freopen("librarian.in", "r", stdin);
	freopen("librarian.out", "w", stdout);
	#endif

	register int i,j,p,mod;
	int n=read();
	int q=read();
	
	for(i=0;i<n;++i) arr[i]=read();
	std::sort(arr,arr+n);
	
//	for(i=0;i<n;++i){
//		if(!(arr[i]/10)) mod[i]=10;
//		else if(!(arr[i]/100)) mod[i]=100;
//		else if(!(arr[i]/1000)) mod[i]=1000;
//		else if(!(arr[i]/10000)) mod[i]=10000;
//		else if(!(arr[i]/100000)) mod[i]=100000;
//		else if(!(arr[i]/1000000)) mod[i]=1000000;
//		else if(!(arr[i]/10000000)) mod[i]=10000000;
//	}
	
	for(i=0;i<q;++i){
		mod=read();
		if(mod==1) mod=10;
		else if(mod==2) mod=100;
		else if(mod==3) mod=1000;
		else if(mod==4) mod=10000;
		else if(mod==5) mod=100000;
		else if(mod==6) mod=1000000;
		else if(mod==7) mod=10000000;
		p=read();
		for(j=0;j<n;++j){
			if(p==arr[j]%mod){
				printf("%d\n",arr[j]);
				goto loop;
			}
		}
		puts("-1");
		loop:;
	}

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

int read(){
    register int x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}
