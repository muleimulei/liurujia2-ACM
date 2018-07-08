#include<stdio.h>

int main1()
{
	double sum=0;
	int n = 1;
	int w = 1;
	double q;
	do{
		q = 1.0 / (2 * n - 1);
		sum += w * q;
		w *= -1;
		n++; 	
	}while(q > 1e-6);
	printf("%.6f\n", sum);
	return 0;
}

int main()
{
	double sum = 0;
	for(int i=0;;i++){
		double term = 1.0 / ( i *2 +1);
		if(i%2==0) sum+= term;
		else sum-= term;
		if(term < 1e-6) break;
	}
	printf("%.6f\n", sum);
	return 0;
}
