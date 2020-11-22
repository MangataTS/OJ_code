#include<cstdio>
#include<algorithm>
#define ll long long
//·µ»ØµÄÊÇGCD(a,b) 
ll extgcd(ll a, ll b, ll &x0, ll &y0) {
	if (!b) {
		x0 = 1, y0 = 0;
		return a;
	}
	ll d = extgcd(b, a%b, x0, y0);
	ll t = x0;
	x0 = y0;
	y0 = t - a / b * y0;
	return d;
}

int main()
{
	ll x,y,m,l,x0,y0,n;
	while(~scanf("%lld%lld%lld%lld%lld",&x, &y, &m, &n, &l)) {
		x0 = 0, y0 = 0;
		ll c = x - y;
		ll a = n - m;
		if(a < 0) {
			a = -a;
			c = -c;
		}
		ll d = extgcd(a, l, x0, y0);
		if (c % d)
			puts("Impossible");	
		else
			printf("%lld\n",(c/d*x0 % (l/d) + l/d) % (l/d));
	}
	return 0;
} 
