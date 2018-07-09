#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<cstdio>
#include<string>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
using namespace std;

int is_prime(int n){ //ÅĞ¶ÏÊÇ·ñÊÇËØÊı 
	if(n<=1) return 0;
	int m = floor(sqrt(n) + 0.5);
	for(int i = 2; i<=m;i++){
		if(n % i ==0) return 0;
	}
	return 1;
}

long long  C(int n, int m){
	if(m < n-m) m = n-m;
	long long ans = 1;
	for(int i = m+1; i<=n; i++) ans *= i;
	for(int i = n-m; i>2; i--) ans /= i;
	return ans;	
}

int cc(int *a){
	printf("%d\n", sizeof(a));
}
int main()
{
	char buf[]="dasda12321qwe";
	int v;
	string s1, s2;
	sscanf(buf, "%s%d%s", s1.c_str(), &v, s2.c_str());
	printf("%s %d %s\n",s1.c_str(), v, s2.c_str());
}
