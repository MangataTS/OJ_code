/*
	作者:Mangata
	路径压缩并查集
*/
#include<cstdio>
const int N =10005;//节点数 
int fa[N],n;
void init(int len) {//初始化，先让每个位置的父节点等于自身 
	for(int i=0;i<=n;++i)
		fa[i]=i;
}
int find(int x) {//查找x的祖先节点 
	int t=x;//路径压缩
	while(t!=fa[t]) 
		t=fa[t];
	while(x!=fa[x]) {
		int temp=fa[x];
		fa[x]=t;
		x=temp;
	}
	return x;
}
void merge(int a,int b) {//将x和y合并 
	a=find(a),b=find(b);
	if(a!=b) {
		fa[b]=a;
		n--;
	}
}
int main()
{
	int t,m,a,b;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		init(n);
		for(int i=1;i<=m;++i) {
			scanf("%d%d",&a,&b);
			merge(a,b);
		}
		printf("%d\n",n);//输出不同类别的总数目
	}
	
	return 0;
}
