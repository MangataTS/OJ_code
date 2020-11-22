/*
	作者:Mangata
	二分模板返回大于x的第一个位置 
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 1005
using namespace std;
int a[N],n,q;
int find(int l,int r,int key)//l为-1,r为数组的长度 
{
	while(l+1<r)
	{
		int mid=l+r>>1;
		if(a[mid]<=key)
		l=mid;
		else
		r=mid;
	}
	return r;//返回大于key的第一个"位置" 
}
int main()
{
	int k;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;++i)
	scanf("%d",&a[i]);
	for(int i=0;i<q;++i)
	{
		scanf("%d",&k);
		printf("%d\n",find(-1,n,k));
	}
} 
