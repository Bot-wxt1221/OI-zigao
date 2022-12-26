#include<ctime>
#include<cstdio>
#define MAX1 100000000
#define MAX2 2147483647

//#define file

int main(){
	#ifdef file
	freopen("work.in", "r", stdin);
	freopen("work.out", "w", stdout);
	#endif

	time_t s=clock();
	
	printf("MAX:%d\n",MAX1);
	s=clock();
	printf("for int i++:");
	for(int i=0;i<MAX1;i++){}
	printf("%f\n",(clock()-s)*1.0/1000);
	
	s=clock();
	printf("for int ++i:");
	for(int i=0;i<MAX1;++i){}
	printf("%f\n",(clock()-s)*1.0/1000);
	
	{s=clock();
	printf("int i for i++:");
	int i=0;
	for(;i<MAX1;i++){}
	printf("%f\n",(clock()-s)*1.0/1000);}
	
	{s=clock();
	printf("int i for ++i:");
	int i=0;
	for(;i<MAX1;++i){}
	printf("%f\n",(clock()-s)*1.0/1000);}
	
	printf("MAX:%d\n",MAX2);
	
	s=clock();
	printf("for register int i++:");
	for(register int i=0;i<MAX2;i++){}
	printf("%f\n",(clock()-s)*1.0/1000);
	
	s=clock();
	printf("for register int ++i:");
	for(register int i=0;i<MAX2;++i){}
	printf("%f\n",(clock()-s)*1.0/1000);
	
	{s=clock();
	printf("for register int i++:");
	register int i=0;
	for(;i<MAX2;i++){}
	printf("%f\n",(clock()-s)*1.0/1000);}
	
	{s=clock();
	printf("for register int ++i:");
	register int i=0;
	for(;i<MAX2;++i){}
	printf("%f\n",(clock()-s)*1.0/1000);}
	
	int a;
	s=clock();
	printf("if i== register int a (for register int ++i):");
	for(register int i=0;i<MAX2;++i)a=i==a;
	printf("%f\n",(clock()-s)*1.0/1000);
	
	s=clock();
	printf("a*=a (for register int ++i):");
	for(register int i=0;i<MAX2;++i)a*=a;
	printf("%f\n",(clock()-s)*1.0/1000);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

long long read(){
    long long x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}
