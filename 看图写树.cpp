#include<cstdio>
#include<cstring>
#include<cctype>
#define maxn 1000+10

char maze[maxn][maxn];
int n;

void solve(int r, int c){
	printf("%c(", maze[r][c]);
	
	if(r + 1 < n && maze[r+1][c]=='|'){ //说明有子节点 
		int l = c;
		while(l-1>=0 && maze[r+2][l-1]=='-' ) l--;
		
		while(maze[r+2][l]=='-' && maze[r+3][l]!=0){
			
			if(!isspace(maze[r+3][l])){
				solve(r+3, l);
			}
			l++;
		}
	}
	printf(")");
}

int main(){
	int t;
	scanf("%d", &t);
	
	getchar();
	while(t--){
		n = 0;
		memset(maze, 0, sizeof(maze));
		
		while(1){
			fgets(maze[n], maxn, stdin);
			if(maze[n][0]=='#') break;
			n++;
		}
		
		int i = 0;
		
		printf("(");
		if(n){
			while(isspace(maze[0][i])) i++;
//			printf("%d %c", n, maze[0][i]);
			solve(0, i);
		} 
		printf(")");
		printf("\n");
	}
	return 0;
}
