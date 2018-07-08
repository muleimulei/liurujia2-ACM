#include<stdio.h>
#include<algorithm>
#define maxn 10000
int v[maxn];

int main(){
	int n, q, kase = 0;
	while(scanf("%d %d", &n, &q)==2 && n){
		
		
		for(int i = 0; i< n;i++){
			scanf("%d", &v[i]);
		}
		std::sort(v, v+n);
		printf("CASE# %d:\n", ++kase);
		while(q--){
			int w;
			scanf("%d", &w);
			int  *p = std::lower_bound(v, v+n, w);
			if(p != (v+n) && *p == w){
				printf("%d found at %d\n", w, p - v + 1);
			}else{
				printf("%d not found\n", w);
			}
		}
	}
	return 0;
} 
