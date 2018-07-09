#include<cstdio>
#include<cstring>

#define maxn 100000+10

char buf[maxn];

int next[maxn];

int main(){
	
	while(scanf("%s", buf+1)!=EOF){
		int cur,last;
		cur = last = 0;
		int n = strlen(buf+1);
		next[cur] = 0;
		
		for(int i = 1; i<=n;i++){
			char c = buf[i];
			if(c == '[') cur = 0;
			else if(c == ']') cur = last;
			else{
				next[i] = next[cur];
				next[cur] = i;
				if(last == cur) last = i; //更新最后一个字符编号 
				cur = i;
			}
		}
		
		for(int i =next[0]; i!=0; i = next[i]){
			printf("%c", buf[i]);
		}
		printf("\n");
	}
	return 0;
} 
