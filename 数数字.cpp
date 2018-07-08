#include<stdio.h>
#include<string.h>
int f[10001][10]={0};

int main(){
//	memset(f, 0, sizeof(f));
	for(int i = 1; i<= 10000; i++){
		for(int j=0; j<10; j++){
			f[i][j] = f[i-1][j];
		}
		int m = i;
		while(m){
			f[i][m%10]++;
			m /= 10;
		}
	}
	
	int t;
	while(!scanf("%d", &t));
//	printf("%d\n", t);
	while(t--){
		int n;
		scanf("%d", &n);
		for(int i=0;i<9;i++){
			printf("%d ", f[n][i]);
		}
		printf("%d\n", f[n][9]);
	}
	return 0;
}

