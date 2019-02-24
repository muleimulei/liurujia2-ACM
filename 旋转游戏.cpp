#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 34;
char ans[10000];
/*
      01    02
      03    04
05 06 07 08 09 10 11
	  12    13
14 15 16 17 18 19 20
      21    22
      23    24
*/ 

// 记录在a数组中， A~H行的下标 
int line[8][7] = {
	{
		1,3,7,12,16,21,23
	},
	{
		2,4,9,13,18,22,24
	},
	{
		11,10,9,8,7,6,5
	},
	{
		20, 19, 18, 17, 16, 15, 14
	},
	{
		24, 22, 18, 13, 9, 4, 2
	},
	{
		23, 21, 16, 12, 7, 3, 1
	},
	{
		14, 15, 16, 17, 18, 19, 20
	},
	{
		5, 6, 7, 8, 9, 10, 11
	}
};

// 中间8个位置在a中的下标 
int center[] = {7, 8, 9, 13, 18,17,16,12};

// 反向移动 
int rev[] = {5, 4, 7, 6, 1, 0, 3 ,2};

int a[maxn+1];
int maxd; // maxd记录深度

// 判断中心8个点是否相同 
bool judge(){
	int b = a[center[0]];
	for(int i = 1; i < 8; i++){
		if(b != a[center[i]]) return false;
	}
	return true;
}

// 沿i方向旋转 
void rotate(int j){
	int start = a[ line[j][0] ];
	for(int i = 1; i<7; i++){
		a[line[j][i-1]] = a[line[j][i]]; 
	}
	a[line[j][6]] = start;
}

int unordered(){
	int n1 =0, n2 = 0, n3 = 0;
	for(int i = 0; i < 8; i++){
		if(a[center[i]]==1) n1++;
		else if(a[center[i]]==2) n2++;
		else n3++;
	}
	return 8 - max(max(n1, n2), n3);
}


// c = 0开始 
bool dfs(int c){
	if(judge()) {
		return true;
	}
	if(c + unordered() > maxd) return false;
	for(int i = 0; i < 8; i++){
		rotate(i);
		ans[c] = i+'A';
		if(dfs(c+1)) return true;
		rotate(rev[i]);
	}
	return false;
}

int main(){
	#ifdef LOCAL
	freopen("1.in", "r", stdin);
	#endif
	while(scanf("%d", &a[1])==1 && a[1]){
		memset(ans, 0, sizeof(ans));
		for(int i = 2; i <=24; i++ ) scanf("%d", &a[i]);
		
		if(judge()){
			puts("No moves needed");
		}else{
			for(maxd = 1; ;maxd++){
				if(dfs(0)){
					break;
				}
			}
			puts(ans);
		}
		printf("%d\n", a[7]);
	}
	return 0;
}

