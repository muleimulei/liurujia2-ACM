#include<stdio.h>
#define maxn 100001

int a[maxn]={0};


int main()
{
	for(int d = 1; d< maxn; d++){
		int sum=d;
		int m = d;
		while(m>0){
			sum += m % 10;
			m /= 10;
		}
		if(a[sum]==0 || d < a[sum]) a[sum]=d;
	}
	
	int t,n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", a[n]);
	}
}
