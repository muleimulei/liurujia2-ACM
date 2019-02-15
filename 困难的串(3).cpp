#include<cstdio>
#include<cstring>
const int maxn = 1000000;
int s[maxn];
int L, n, cnt;

int dfs(int cur){
	if(cur == n) {
		for(int i = 0; i < cur; i++){
			printf("%c", 'A'+ s[i]);
		}
		printf("\n");
		return 0; // 返回0表示已经得到解了，无需继续搜索 
	}else{
		for(int i = 0; i < L; i++){
			s[cur] = i;
			int ok = 1;
			for (int j = 1; j*2 <= cur+1; j++) {
				int equal =  1;
				for(int k = 0; k < j; k++){
					if(s[cur-k] != s[cur-k-j]){
						equal = 0;
					}
				}
				if(equal) ok = 0;
			}	
			if(ok){
				if(!dfs(cur+1)) return 0;
			}
		}
	}
}

int main(){
	while(scanf("%d%d", &n, &L)==2 && L && n){
		memset(s, -1, sizeof(s));
		cnt = 0;
		dfs(0);
	}
	
	return 0;
}
