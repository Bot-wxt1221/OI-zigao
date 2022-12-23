#include<bitset>
#define DATA_TYPE long long
const int MAX_NUM=100000000+10;std::bitset<MAX_NUM>isPrime;DATA_TYPE prime[MAX_NUM];void Euler(DATA_TYPE n){register int cnt=0;for(register int i=2;i<=n;++i){if(!isPrime[i])prime[++cnt]=i;for(register int j=1;j<=cnt&&prime[j]*i<=n;++j){isPrime.set(prime[j]*i,1);if(!i%prime[j])break;}}}