#include<cstdio>
#include<cstring>


int maze[26][26]; 
int in[26], out[26], vis[26];

void dfs(int v){
	for(int i = 0; i < 26; i++){
		if( (maze[v][i] || maze[i][v] ) && vis[i]==0){
//			if(vis[i]==0){
				vis[i] = 1;
				dfs(i);
//			}
		}
	}
}

bool liantong(){
	int num = 0;
	for(int cnt = 0; cnt < 26; cnt++){
		if( (in[cnt] || out[cnt] ) && vis[cnt]==0 ) {
			vis[cnt] = 1;
			dfs(cnt);
			num++;
		}
	}
	return num==1;
}
bool lujing(){
	int n=0, n1=0, n2 = 0;
	for(int i = 0; i< 26; i++){
		if(in[i] == out[i]) continue;
		else {
			n++;
			if(n > 2) return false; //最多有两个点的出入度不等 
			if(in[i]==(out[i]+1)) {n1=n1+1; continue;}

    		if(in[i]==(out[i]-1)) {n2=n2+1; continue;}
			return false;
		}
	}
	if(n==0){
		return true;
	}else{
		if(n==2){
			if(n1==1 && n2==1) return true;
			else return false;
		}else{
			return true;
		}
	}

}


int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		memset(maze, 0, sizeof(maze));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(vis,0 , sizeof(vis));
		
		int num;
		scanf("%d", &num);
		for(int i = 0; i<num;i++){
			char s[1000+10];
			scanf("%s", s );
			char f = s[0], l = s[strlen(s)-1];
			
			maze[f-'a'][l-'a'] = 1;
			out[f - 'a'] ++;
			in[l - 'a']++;
		}
		
		bool f1 = liantong();
		if(!f1){
			puts("The door cannot be opened.");
		}else{
			bool f2 = lujing();
			if(!f2){
				printf("The door cannot be opened.\n");
			}else{
				printf("Ordering is possible.\n");
			}
		}
//		if(t) printf("\n");
	}
	return 0;
} 
