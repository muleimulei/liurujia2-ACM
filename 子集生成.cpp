#include<vector>
#include<cstdio>

void print_subset(int n, int *a, int cur){
	if(cur == n){
		for(int i = 0; i < cur; i++){
			if(a[i]) printf("%d ", i) ;
		} 
		printf("\n");
		return ;
	}
	a[cur] = 1;
//	printf("p: %d\n", cur);
	print_subset(n, a, cur+1);
	a[cur] = 0;
//	printf("n: %d\n", cur);
	print_subset(n, a, cur+1);
}

void print(int n, int s){
	for(int i = 0; i<n;i++){
		if(s & 1<<i) printf("%d ", i);
	}
	printf("\n");
}





int main(){
	int b[10];
//	print_subset(3, b, 0);z
	int  n = 3;
	for(int i = 0; i < (1<<n); i++){
		print(n, i);
	}
	return 0;
}
