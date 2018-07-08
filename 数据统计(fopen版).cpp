#include<stdio.h>
#define INF 1000000000

int main()
{
	FILE *fin, *fout;
	fin = fopen("data.in","r");
//	fout = fopen("data.out", "w");
	
	int x, n = 0, min = INF, max = -INF, s = 0;
	while(fscanf(fin, "%d", &x)!=EOF){
		s += x;
		if(x<min) min = x;
		if(x>max) max = x;
		n++;
	}
	printf("%d %d %.3f", min, max, double(s)/n);
	fclose(fin);
	return 0;
}

