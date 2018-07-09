#include<cstdio>

int main(){
	int num;
	while(scanf("%d", &num)==1 && num!=-1){
		while(num--){
			int D, I;
			scanf("%d %d", &D, &I);
			
			int k = 1;
			for(int i = 0; i<D-1; i++){
				if(I%2) {
					k = k*2;
					I = (I+1)/2;
				}else{
					k = k*2+1;
					I /= 2;
				}
			}
			printf("%d\n", k);
		}
	}
	return 0;
}
