/*
    作者:Mangata
    朴素素数判断模板 	
*/
#include<cstdio>
#include<algorithm>
#include<cstring>

bool is_prime(int x) {
	if(x == 0 || x == 1)
	return false;
	for(int i = 2; i*i <= x; ++i) {
		if(x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	while(~scanf("%d",&x)) {
		if (is_prime(x))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
