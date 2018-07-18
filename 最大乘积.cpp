#include<cstdio>

int main(){
//	freopen("1.txt", "w+", stdout);
	int kase = 0;
	int num;
	
	int a[20];
	while(scanf("%d", &num)!=EOF){
		for(int i = 0; i<num; i++){
			scanf("%d", &a[i]);
		}
		long long max = -100000000;
		long long ans;
		for(int first = 0; first < num; first++){
			for(int last = first; last< num; last++){
				int i = first;
				ans = 1;
				while(i <= last){
					ans *= a[i];
					i++;
				}
				if(ans>max){
					max = ans;
				}
				
			}
		}
		
		printf("Case #%d: The maximum product is %lld.\n\n", ++kase, max > 0? max : 0);
		getchar();
	} 
	return 0;
}
