#include<cstring>
#include<cstdio>
#include<sstream>
#define maxn 100000+10 

int num;

int mid_order[maxn], post_order[maxn];

int lch[maxn], rch[maxn];

bool read_order(int *a){
	num = 0;
	char buf[maxn];
	if(fgets(buf, maxn, stdin)==NULL) return false; 
	std::stringstream ss(buf);
	int v;
	while(ss>>v){
		a[num++] = v;
	}
	return num>0;
}

// 把mid_order[L1..L2]和 post_order[L2..R2]建成一颗二叉树，返回树根
int build(int L1, int R1, int L2, int R2){ //根据中序和后续构建 
	if(L1 > R1) return 0;
	int root = post_order[R2];
	int p = L1;
	while(mid_order[p]!=root) p++;
	int n = p - L1; // 左子树的节点个数
	lch[root] = build(L1, p-1, L2, L2+n-1);
	rch[root] = build(p+1, R1, L2+n ,R2-1);
	return root;
}

int best, best_sum; //目前为止的最优解和对应的权和 

void dfs(int a, int sum){ // 前序遍历，找到权值和最小的路径 
	sum+= a;
	if(lch[a] ==0 && rch[a]==0 ){
		if(sum < best_sum || sum == best_sum && best > a){
			best_sum = sum;
			best = a;
		}
	}
	if(lch[a]!=0) dfs(lch[a], sum);
	if(rch[a]!=0) dfs(rch[a], sum); 
}

int main(){
	while(read_order(mid_order)){
		read_order(post_order);
		build(0, num-1, 0, num-1);
		best_sum = 1000000000;
		dfs(post_order[num-1], 0); // 
		
		printf("%d\n", best); //前序遍历 
	}
	return 0;
} 
