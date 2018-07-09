#include<cstdio>
#include<cstring>
#define maxn (1<<20) +10

int s[maxn];

int main(){
	int num;
	while(scanf("%d", &num)==1 && num!=-1){
		while(num--){
			memset(s, 0, sizeof(s));
			int k, D, I;
			scanf("%d %d", &D, &I);
			int n = (1<<D) - 1;
			for(int i = 0; i < I; i++){
				k = 1;
				while(1){
					s[k] = !s[k];
					k = s[k]? k*2: k*2+1;
					if(k>n) break;
				}
			}
			printf("%d\n", k / 2);
		}
	}
	return 0;
}
