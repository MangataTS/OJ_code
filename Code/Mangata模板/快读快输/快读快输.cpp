/*
	作者:Mangata
	int的快读快输 
*/
#include<cstdio>
inline int read()
{
	int x=0;
	bool fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	fg=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	if(fg)
	return x;
	return ~(x-1); 
}
inline int write(int x)
{
	if(x<0)
	{
		x=~(x-1);
		putchar('-');
	}
	int s[20];
	int top=0;
	while(x)
	{
		s[++top]=x%10;
		x/=10;
	}
	if(!top) s[++top]=0;
	while(top)
	putchar(s[top--]+'0');
}

int main()
{
	while(1){
	int n=read();
	write(n);
	putchar('\n');
	}
	return 0;
}
