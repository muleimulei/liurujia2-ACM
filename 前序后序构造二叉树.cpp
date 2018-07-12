#include<cstdio>
#include<sstream>
#define maxn 1000

int mid_order[maxn], post_order[maxn];

struct node{
	node * left;
	node * right;
	int v;
	node(int m):left(NULL), right(NULL), v(m){}	
};

node *root=NULL;
int num;
char buf[maxn];

bool read_input(int *arr){
	if(fgets(buf, maxn, stdin)==NULL) return false;
	num = 0;
	std::stringstream ss(buf);
	int v;
	while(ss>>v){
		arr[num++] = v;
	}
	return true;
}

void build(int s1, int e1, int s2, int e2, node * &root){
	if(s1 > e1) return;
	
	int v = post_order[e2];
	if(root==NULL){
		root = new node(v);
	}
	int p = s1;
	while(mid_order[p]!=v) p++;
	
	int n = p - s1;
	
	build(s1, p-1, s2, s2+n-1, root->left);
	build(p+1, e1, s2+n, e2-1, root->right);
}

void dfs(node *root){
	if(!root) return;
	printf("%d ", root->v);
	dfs(root->left);
	dfs(root->right);
}
int main(){
	while(read_input(mid_order)){
		read_input(post_order);
		build(0, num-1, 0, num-1, root);
		
		dfs(root);
	}

}
