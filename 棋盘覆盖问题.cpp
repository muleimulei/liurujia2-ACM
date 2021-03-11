#include<stdio.h>

int solve(int k)
{
	if(k==1) return 1;
	else 4*solve(k-1)+1;
}

int main()
{
	int k;
	scanf("%d", &k);
	printf("%d\n", solve(k1));
	return 0;	
}

