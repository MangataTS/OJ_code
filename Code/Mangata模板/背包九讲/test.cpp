#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int V;
long long f[1005];
int main()
{
	scanf("%d",&n);
	V=n*(n+1)/2;
	if(V&1)
	printf("0\n");
	else
	{
		V/=2;
		f[0]=1;
		for(int i=1;i<=n;++i)
		{
			for(int j=V;j>=i;--j)
			{
				f[j]+=f[j-i];	
			}
		}
		printf("%lld\n",f[V]/2);	
	}
	return 0;
} 
