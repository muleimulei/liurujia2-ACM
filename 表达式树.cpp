#include<cstdio>

const int maxn = 1000;
int lch[maxn], rch[maxn]; char op[maxn]; //每个节点的左右子节点编号和字符 
int nc = 0; // 节点数 
 
int build_tree(char *s, int x, int y){
	int i, c1 = -1, c2 = -1, p = 0;
	int u;
	if(y-x==0) {
		u = ++nc;
		lch[u] = rch[u] = 0;
		op[u] = s[x];
		return u; 
	}
	for(i = x; i < y; i++){
		switch (s[i]){
			case '(': p++; break;
			case ')': p--; break;
			case '+': case '-': if(!p) c1 = i; break;
			case '*': case '/': if(!p) c2 = i; break;
		}
	}
	
	if(c1 < 0) c1 = c2; // 找不到括号外的加减号，就用乘除号
	if(c1 < 0) return build_tree(s, x+1, y-1); // 整个表达式被一对括号括起来 
	
	u = ++nc;
	lch[u] = build_tree(x, x, c1);
	rch[u] = build_tree(x, c1+1, y); 
	op[u] = s[c1];
	return u;
	
}
 
