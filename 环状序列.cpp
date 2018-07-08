#include<stdio.h>
#define maxn 101
#include<string.h>

int less(char *s, int p, int q){
	int n = strlen(s);
	for(int i = 0; i<n; i++){
		if(s[(p+i)%n] != s[(q+i)%n] ){
			return s[(p+i)%n] < s[(q+i)%n];
		}
	}
	return 0;
}


int main()
{
	int T;
	char s[maxn];
	scanf("%d", &T);
	while(T--){
		scanf("%s", s);
		int ans = 0;
		int n = strlen(s);
		
		for(int i = 1; i< n;i++){
			if(less(s, i, ans)) ans = i;
		}
		
		for(int i = 0; i<n;i++){
			putchar(s[(i + ans) % n]);
		}
		putchar('\n');
	}
}



bool cmp(int s, int p, char buf[], int len){
	
	for(int i = 0; i<len;i++, s++, p++){
		if(s>=len) s = s - len;
		if(p>=len) p = p - len;
		
		if(buf[p]<buf[s]){
//			printf("%c %c\n", buf[p], buf[s]);
			return true;
		}else if(buf[p]==buf[s]){
			continue;
		}else{
			return false;
		}
	}
	
}


int main1(){
	int n;
	while(scanf("%d", &n)!=EOF && n){
		while(n--){
			char buf[maxn];
			scanf("%s", buf);
			
			int len = strlen(buf);
			int s = 0;
			int p = s + 1;
			while(p<len){
				bool f = cmp(s, p, buf, len);
				if(f){
					s = p;
//					break; 
				}
				p++;
			}
//			printf("%d\n", s);
			
			
			for(int i = 0; i<len;i++, s++){
				if(s<len){
					printf("%c", buf[s]);
				}else{
					printf("%c", buf[s-len]);
				}
			}
			puts("");
		}
	}
}
