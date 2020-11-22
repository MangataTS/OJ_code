/*
	作者:Mangata
	完全背包问题模板  滚动数组优化 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10005
int f[N];
int v[N],w[N];
int n,V;
int main()
{
	scanf("%d%d",&n,&V);
	for(int i=1;i<=n;++i)	scanf("%d%d",&w[i],&v[i]);
	for(int i=1;i<=n;++i)
	{
		for(int j=w[i];j<=V;++j)
		{
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
	}
	printf("%d\n",f[V]); 
	return 0;
}
