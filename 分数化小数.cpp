#include<stdio.h>
#include<math.h>

int main()
{
	int a,b,c;
	int kase = 0;
	while(scanf("%d %d %d", &a, &b, &c)==3 && a && b && c){
		printf("Case %d: %d.", ++kase, a/b);
		a %= b;
		
		for(int i=1; i<c;i++){
			printf("%d", a * 10 / b);
			a = a*10 % b;
		}
		
		if(a * 10 % b * 10 / b >=5 ){
			printf("%d\n", a * 10 / b +1 );
		}else{
			printf("%d\n", a * 10 / b );
		} 
	}	
}
