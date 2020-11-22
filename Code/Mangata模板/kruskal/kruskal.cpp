#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 205
struct node{
	int from,to;
	long long cost;
}E[N*N];
int fa[N],n,m;
bool cmp(node a,node b){
	return a.cost<b.cost;
}
int find(int x){
	while(x!=fa[x])
	x=fa[x];
	return x;
}
void init(){
	for(int i=1;i<=n;++i)
	fa[i]=i;
}
int same(int x,int y){
	return find(x)==find(y);
}
void merge(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b)
	fa[b]=a;
}
long long kruskal(){
	long long ans=0;
	sort(E+1,E+m+1,cmp);
	for(int i=1;i<=m;++i){
		if(same(E[i].from,E[i].to))
		continue;
		merge(E[i].from,E[i].to);
		ans+=E[i].cost;
	}
	return ans;
}
int main(){
	int u,v,w;
	while(~scanf("%d%d",&m,&n)&&m)
	{
		init();
		for(int i=1;i<=m;++i){
			scanf("%d%d%d",&u,&v,&w);
			E[i].from=u,E[i].to=v,E[i].cost=w;
		}
		long long k=kruskal();
		int loc=find(1);
		for(int i=2;i<=n;++i)
			if(find(i)!=loc){
			k=-1;
			break;
		}
		if(k==-1)
		puts("?");
		else
		printf("%lld\n",k);
	}
	return 0;
}
