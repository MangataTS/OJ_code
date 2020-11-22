#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//快速幂 
ll quick_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while(n > 0) {
		if(n & 1)	res = (res * x)% mod;
		x = (x * x) % mod;
		n >>= 1;
	}
	return res;
}
//快速乘 
ll quick_pow2(ll x, ll n, ll mod) {
	ll res = 0;
	x%= mod;
	n%= mod;
	while(n) {
		if(n & 1) {
			res = (res + x) % mod;
		}
		x = (x%mod + x%mod) % mod;
		n >>= 1;
	}
	return res%mod;
} 
int main()
{
	ll a,b,c,n;
//	while(~scanf("%lld%lld%lld",&a,&b,&c)) {
//		printf("%lld\n",quick_pow(a,b,c));
//	}
	ll key,temp; 
	while(~scanf("%lld%lld",&n,&c)) {
		scanf("%lld",&key);
		key %= c;
		for(ll i = 1; i < n; ++i) {
			scanf("%lld",&temp);
			key = quick_pow2(key,temp,c);
		}
		printf("%lld\n",key);
	}
	return 0;
} 
