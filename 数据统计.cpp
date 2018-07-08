#include<stdio.h>

int main()
{
	int x, n, min, max,s=0;
	scanf("%d", &x);
	min = max = s = x;
	n = 1;
	
	while(scanf("%d", &x)==1){
		s += x;
		n++;
		if(x > max) max = x;
		if(x<min) min = x;	
	}
	printf("%d %d %.3f", min, max, (double)s / n);
	return 0;
}
