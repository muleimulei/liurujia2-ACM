#include<cmath>
#include<cstdio>
#include<cstring>
int maze[10][10], n; 

bool place(int h, int l){
	for(int i = 0; i< h; i++){
		for(int j = 0; j < n; j++){
			if(maze[i][j]){
				if(l == j || abs(h - i) == abs(j - l)){
					return false;
				}
			}
			
		}
	}
	return true;
}



void queen(int n, int h){
	if(h == n ){
		for(int i = 0; i< n; i++){
			for(int j = 0; j < n; j++){
				printf("%d ", maze[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	else{
		for(int i = 0; i < n;i++){
			if(place(h, i)){
				maze[h][i] = 1;
				queen(n , h+1);
				maze[h][i] = 0;
			}
			
		}
	}
} 

int main(){
	
	scanf("%d", &n);
	memset(maze, 0, sizeof(maze));
	queen(n, 0);
	return 0; 
} 
