/*
	作者:Mangata
	多重背包问题模板  二进制枚举优化 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10005
int f[N];
int v[N],w[N],p[N];
int n,V;
int main()
{
	scanf("%d%d",&n,&V);
	for(int i=1;i<=n;++i)	scanf("%d%d%d",&w[i],&v[i],&p[i]);
	for(int i=1;i<=n;++i)
	{
		int num=min(p[i],V/w[i]);
		for(int k=1;num>0;k<<=1)
		{
			if(k>num)
			k=num;
			num-=k;
			for(int j=V;j>=w[i]*k;--j)
				f[j]=max(f[j],f[j-w[i]*k]+v[i]*k);
		}
	}
	printf("%d\n",f[V]); 
	return 0;
}
