#include<stdio.h>

#define OFFSET 500000 //偏移量，用于补偿实际数字与数组下标之间的偏移
int hash[1000001]; // hash数组，记录每个数字是否出现，不出现为0，出现后被标记为1 
 
int main()
{
	int n,m;
	while(scanf("%d %d", &n, &m)!=EOF){
		for(int i=-500000; i<=500000; i++){
			hash[OFFSET+i]=0; // 初始化，将每个数字标记为未出现 
		}
		for(int i=0; i<n;i++){
			int x;
			scanf("%d", &x);
			hash[OFFSET+x]=1; // 凡是出现过的数字，该数组元素均被设置成1 
		}
		
		for(int i=500000; i>=-500000; i--){ // 输出前m个数 
			if(hash[OFFSET+i]==1){
				printf("%d", i);
				m--;
				if(m!=0) printf(" ");
				else {
					printf("\n");
					break; 
				}
			}
		}
	} 
	
	
	
/*
	int n, m;
	int buf[n];
	while(scanf("%d %d", &n, &m)!=EOF && n!=0){
		for(int i=0; i<n;i++){
			int x;
			scanf("%d", &x);
			buf[i]=x;
		}
		for(int i=0;i<m;i++){
			for(int j=0; j<n-1-i;j++){
				if(buf[j]> buf[j+1]){
					int tmp = buf[j];
					buf[j] = buf[j+1];
					buf[j+1] = tmp;
				}
			}
		}
		
		for(int i=0; i< m;i++){
			if(i==0){
				printf("%d", buf[n-i-1]);
			}else{
				printf(" %d", buf[n-i-1]);
			}
		}
		printf("\n");
		
	}
*/
	return 0;
}
