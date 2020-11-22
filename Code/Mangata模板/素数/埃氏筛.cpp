/*
    作者:Mangata
    埃式筛模板 	
*/
//时间复杂度 :O(n*log(log(n))) 
#include<cstdio>
#include<algorithm>
#include<cstring>

const int N = 10000005;
bool vis[N] = {true,true};//初始化 

int main()
{
	int n,x;//离线处理 
	for(int i = 2; i*i <= N; ++i) {
		if (!vis[i]) {
		for(int j = i*2; j <= N; j += i) //把素数的倍数筛掉 
			vis[j] = true;		
		}
	}
	while(~scanf("%d",&x)) {
	if (vis[x])
		puts("No");
	else
		puts("Yes");
}
	return 0;
} 
