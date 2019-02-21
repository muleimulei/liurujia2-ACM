#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;


const int maxn = 1000;

int v[maxn],ans[maxn]; 
int maxd;

// 获得1/c<=a/b 的最小 C 
int get_first(int a, int b){
	return b/a+1;
}

// 如果当前解V比目前最优解ans更优，更新
bool better(int d){
	for(int i = d; i>=0; i--){
		if(v[i]!=ans[i] ){
			return ans[i]== -1 || v[i] < ans[i];
		}
	}
	return false;
}


int gcd(int a, int b){
	return b==0? a: gcd(b, a%b);
}

// 当前深度为d, 分母不能小于from，分数之和恰好为aa/bb
bool dfs(int d, int from, int aa, int bb){
	if( d== maxd ){
		if(bb % aa) return 0; // aa/bb必须是埃及分数 
		v[d] =  bb / aa;
		if(better(d)){
			memcpy(ans, v, sizeof(int)*(d+1));
		}
		return 1;
	}
	bool ok = 0;
	from = max(from, get_first(aa, bb)); // 枚举的起点
	for(int i = from; ; i++){
		// 剪枝： 如果剩下的maxd+1-d个分数全部都是1/i，加起来仍然不超过aa/bb,则无解
		if(bb * (maxd+1-d) <= i*aa )  break;
		v[d] = i;
		// 计算aa/bb-1/i,计算结果为a2/b2
		int b2 = bb*i;
		int a2 = aa*i - bb;
		
		int g = gcd(a2, b2); //以便约分
		if(dfs(d+1, i+1, a2/g, b2/g)) {
			ok = 1;
		}
	}
	return ok;
}


int main(){
	int a, b, kase = 0;
	while(scanf("%d%d", &a, &b)==2){
		printf("Case %d: ", ++kase);
		
		int ok = 0;
		for(maxd = 1; ; maxd++){
			memset(ans, -1, sizeof(ans));
			if(dfs(0, get_first(a, b), a, b)){
				ok = 1;
				break;
			}
		}
		
		if(ok){
			printf("%d/%d=1/%d", a, b, ans[0]);
			for(int i = 1; i < maxd; i++){
				printf("+1/%d", ans[i]);
			}
			printf("+1/%d\n", ans[maxd]);
		}else{
			printf("No solution\n");
		}
	}
	
	return 0;
}
