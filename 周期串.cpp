#include<stdio.h>
#include<string.h>

int main(){
	char buf[81];
	int t;
	while(!scanf("%d", &t));
	while(t--){
		scanf("%s", buf);
		int len = strlen(buf),k;
		for(int i = 1; i<=len;i++){
			if(len%i==0){
				for(k = i; k<len;k++){
					if(buf[k] != buf[k%i]) break;
				}
				
				if(k==len){
					printf("%d\n", i);
					break;
				}
			}
		}
		if(t){
			printf("\n");
		}
	}
	return 0;
}
