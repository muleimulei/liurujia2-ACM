#include<stdio.h>

int main()
{
	int a[1001];
	int n,k,first=0;
	while(scanf("%d %d", &n, &k)!=EOF && n){
		for(int i=1; i<=n; i++){
			a[i]=1;
		}
		
		for(int i=2; i<=k;i++){
			int s = i;
			for(; s<=n;s++){
				if(s % i ==0){
					a[s] = a[s]==0?1:0;
				}
			}
		}
		
		for(int i=1; i<=n; i++){
			if(a[i]){
				if(!first) {
				first =1;
			}else{
				printf(" ");	
			}
			printf("%d", i);
			}
		}
		puts("");
	}
}
