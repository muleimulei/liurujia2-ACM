#include<cstdio>
#include<cstring>
const int maxn = 100000;

char buf1[maxn],  buf2[maxn];

int lch[maxn], rch[maxn];


int build( int s1, int e1, int s2, int e2 ){
	if(s1>=e1) return -1;
	int root = buf1[s1] - 'A';
	
	int p = s2;
	while(buf2[p]-'A' - root!=0) p++;
	
	int cnt = p - s2; // 左子树节点个数 
	
	lch[root] = build(s1+1,  s1+1+cnt  ,s2, s2+cnt);
	rch[root] = build(s1+1+cnt, e1, p+1, e2);
	return root;
}

void show(int root){
	if(root==-1) return;
	show( lch[root] );
	show( rch[root] );
	printf("%c", root+'A');
}

int main(){
	while(scanf("%s", buf1)!=EOF){
		scanf("%s", buf2);
		memset(lch, -1, sizeof(lch));
		memset(rch, -1, sizeof(rch));
		
		int root = build(0, strlen(buf1), 0, strlen(buf2));
		show(root);
		printf("\n");
	}
}
