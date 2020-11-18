#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 233333333;
ll quick_pow(ll a,ll b, ll mod) {
	ll res = 1;
	while(b) {
		if(b&1) res = (res%mod * a%mod) %mod;
		b>>=1;
		a = (a%mod * a%mod) % mod;
	}
	return res%mod;
}
int main()
{
	ll a,b,c;
	while(~scanf("%lld%lld%lld",&a,&b,&c)) {
		ll sum = 0;
		for(ll i = 0; i < c; ++i) {
			sum = (sum%mod+(quick_pow(a,i,mod) + quick_pow(b,c-i-1,mod))%mod)%mod;
		}
		printf("%lld\n",sum%mod);
	}
	return 0;
}
