/*
	作者:Mangata
	GCD的四种写法
*/
#include<cstdio>
int gcd_1(int a,int b){//辗转相除法 循环写法 
	while(b>0) {
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}
int gcd_2(int a,int b) {//辗转相除法 递归写法 
	return b?gcd_2(b,a%b) : a;
}
int gcd_3(int a,int b) {//更相减损法 递归写法 
	if(a == 0)
		return b;
	if(b == 0)
		return a; 
	if(a == b)
		return a;
	if(a > b)
		return gcd_3(a-b,b);
	if(a < b)
		return gcd_3(b-a,a);
}
int gcd_4(int a,int b) {//更相减损法 循环写法 
	if(a == 0)
	return b;
	if(b == 0)
	return a;
	while(a != b) {
		if(a > b)
			a -= b;
		else
		{
			int t = a;
			a = b - a;
			b = t;
		}
	}
	return a;
}
int main()
{
	int a,b;
	while(~scanf("%d%d",&a,&b))
		printf("gcd_1=%d\ngcd_2=%d\ngcd_3=%d\ngcd_4=%d\n",gcd_1(a,b),gcd_2(a,b),gcd_3(a,b),gcd_4(a,b));
}
