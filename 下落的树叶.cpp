#include<cstdio>
#include<cstring>
#include<sstream>
#define maxn 100

int ans[maxn];
int n;

void doit(int mid){
	int v;
	scanf("%d", &v);

	if(v==-1) return;
	else ans[mid] += v;
	
	
	doit(mid-1);
	doit(mid+1);
}

bool read_init(){
		memset(ans, 0, sizeof(ans));
	int v;
	scanf("%d", &v);
	if(v==-1) return false;
	
	int m = maxn / 2;
	ans[m] =v;
	
	doit(m-1);
	doit(m+1);
}

int main(){
	int kase=0;
	while(read_init()){
		int p = 0;
		while(ans[p]==0) p++;
		printf("Case %d:\n%d", ++kase, ans[p++]);
		while(ans[p]!=0){
			printf(" %d", ans[p++]);
		}
		printf("\n\n");
	}
	
	return 0;
}
