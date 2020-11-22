#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10005
int nextt[N];
char S[N],T[N];
int len1,len2;
void get_next(){//获取next数组 
	int i=0,j=-1;
	nextt[0]=-1;//很重要 
	while(i<len1){
		if(j==-1||S[i]==S[j])
			nextt[++i]=++j;
		else
		j=nextt[j];
	}
}
int kmp(){//返回的是子串在主串中存在的次数 
	int cnt=0;//表示的是子串在主串中存在的次数 
	int i=0,j=0;
	get_next();
	while(i<len2)
	{
		if(j==-1||T[i]==S[j])
		i++,j++;
		else 
		j=nextt[j];
		if(j==len1)//当匹配成功 
		j=0,cnt++;//子串指针归零 
	}
	return cnt;
}
int main(){
	while(~scanf("%s",T))
	{
		if(T[0]=='#')
		break;
		scanf("%s",S);
		len1=strlen(S);
		len2=strlen(T);
		printf("%d\n",kmp());
	}
	return 0;
}
