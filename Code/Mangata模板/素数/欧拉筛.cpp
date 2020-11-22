/*
    作者:Mangata
    欧拉筛模板 	
*/
//时间复杂度为  O(n) 
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

const int N = 10000005; 
int prime[N];
bool vis[N];

void get_prime() {
	memset(vis,true,sizeof vis);
	memset(prime,0,sizeof prime);
	vis[0] = vis[1] = false;
	for(int i = 2; i <= N; ++i) {
		if (vis[i]) {
			prime[++prime[0]] = i;
		}
		for(int j = 1;j <= prime[0] && i*prime[j] <= N; ++j) {
			vis[i * prime[j]] = false;
			if (i % prime[j] == 0) //避免重复筛选               
				break;
		}	
	}
}

int main()
{
	int n;
	get_prime();
	while(~scanf("%d",&n)) {
		if (vis[n])
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
