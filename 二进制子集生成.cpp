#include<cstdio> 

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < (1<<n); i++){
		for(int j = 0; j < n;j++){
			if( i & (1<<j)){
				printf(" %d", j);
			}
		}
		printf("\n");
	}
	
	return 0;
}

