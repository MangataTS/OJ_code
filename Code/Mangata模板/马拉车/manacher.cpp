/*
	作者:Mangata
	manacger模板 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 210005
char S[N],str[N*2+5];
int len1,len2,ans,p[N*2+5];
void init(){//数组初始化，即数组长度翻倍 
    str[0]='$';//为了防止数组越界 
    str[1]='#';
    for(int i=0;i<len1;++i){
        str[i*2+2]=S[i];
        str[i*2+3]='#';
    }
    len2=len1*2+2;
    str[len2]='*';
}
void manacher(){//manacher 
    init();
    int id=0,mx=0;//mx表示的是当前计算回文串最右边字符的最大值 
    for(int i=0;i<len2;++i){
        p[i]=mx >i?min(p[id*2-i],mx-i):1;//p[i]=mx>i?min(p[id*2-i],m-i):1; 
        for(;str[i+p[i]]==str[i-p[i]];p[i]++);//如果字符串对称则对称长度增加 
        if(p[i]+i>mx)//如果大于当前的最大长度则更新 
        mx=p[i]+i,id=i;
    }
}
int main(){
    while(~scanf("%s",S)){
        len1=strlen(S);
        manacher();
        int maxlen=0;
        for(int i=0;i<len2;++i)
            maxlen=max(p[i],maxlen);
        printf("%d\n",maxlen-1);
    }
    return 0;
}
