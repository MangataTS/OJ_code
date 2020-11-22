#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define P pair<int, int>
#define INF 0x3f3f3f3f

const int N = 1005;
int mp[N][N];
bool vis[N];
int dis[N];
int n,m;

//返回的是一个生成树每条边的和 
int prim(int s) {
	for(int i = 1; i <=n ; ++i) {
		dis[i] = INF;
		vis[i] = false;
	}
	dis[s] = 0;
	int ans = 0;
	while(true) {
		int v = -1;
		for(int u = 1; u <= n; ++u) {
			if(!vis[u] && (v == -1 || dis[u] < dis[v])) {
				v = u;
			}
		}
		if(v == -1)
		break;
		vis[v] = true;
		ans += dis[v];
		//松弛操作 更新最短路径 
		for(int u = 1; u <= n; ++u) {
			dis[u] = min(dis[u], mp[u][v]);
		}
	}
	return ans; 
}

int main()
{
	int u,v,cost;
	while(~scanf("%d%d",&m, &n) && m) {
		memset(mp,INF,sizeof mp);
		for(int i = 0; i < m; ++i) {
			scanf("%d%d%d",&u, &v, &cost);
			if(mp[u][v] > cost)
			mp[u][v] = mp[v][u] = cost;
		}
		int ans = prim(1);
		if(ans < INF) {
			printf("%d\n",ans);
		} else {
			puts("?");
		}
	}
	return 0;
}
