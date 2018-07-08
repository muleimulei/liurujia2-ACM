#include<stdio.h>

int main()
{
	int n,m;
	int kase = 0;
	while(scanf("%d%d", &n, &m)==2 && n && m){
		double sum = 0;
		
		while(n<=m){
			double t = 1.0 / n;
			t *= t;
			sum+=t;
			n++;
		}
		printf("Caes %d: %.5lf\n", ++kase, sum);
	}
	return 0;
}
