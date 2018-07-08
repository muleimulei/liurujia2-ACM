#include<stdio.h>
#include<time.h>

int main()
{
	const int mod = 1000000;
	int n, s = 0;
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++){
		int fac = 1;
		for(int j=1; j<=i; j++){
			fac = (fac * j) % mod;
		}
		s = (s + fac ) % mod;
	}
	printf("%d\n", s);
	printf("Time used = %.2f\n", (double) clock() / CLOCKS_PER_SEC);
} 
