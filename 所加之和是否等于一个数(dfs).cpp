#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 100;
int buf[] = {9,1,8,2,10,3,7,4,6,5};

int mark[maxn];

int ans[maxn],num;


// 如果所加之和正好为T，则返回1，否则返回-1 
int dfs(int cur, int T){
	if(T==0){
		return 1;
	} 
	for(int i = cur; i < 10; i++){
		if(!mark[i]&& buf[i] <= T){
			ans[cur] = buf[i];
			mark[i] = 1;
			num++;
			if(dfs(cur+1, T-buf[i])){
				return 1;	
			}
			num--;
			mark[i] = 0;
		}
	}
	return 0;
}


int main(){
	int T;
	sort(buf, buf+10);
	while(scanf("%d", &T)==1){
		memset(mark, 0, sizeof(mark));
		num=0;
		if(dfs(0, T)){
			puts("1");
			for(int i = 0; i < num; i++){
				printf("%d ", ans[i]);
			}
			printf("\n");
		}else{
			puts("-1");
		}
	} 
	return 0;
}
