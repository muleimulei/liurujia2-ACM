#include<stdio.h>
#include<string.h>

#define maxn 100

int left, chance;
char s[maxn], s2[maxn]; // 答案是s,玩家猜的字母是s2
int win,  lose; 

void guess(char ch){
	int bad = 1;
	for(int i = 0; i< strlen(s); i++){
		if(s[i] == ch){
			left--;
			bad = 0;
			s[i]=' ';
		}
	}
	
	if(bad) chance--;
	if(!chance) lose = 1;
	if(!left) win = 1;
}

int main()
{
	int rnd;
	while(scanf("%d %s %s", &rnd, s, s2)==3 && rnd !=-1){
		printf("Round %d\n", rnd);
		win = lose = 0;
		left = strlen(s);
		chance = 7;
		for(int i = 0; i< strlen(s2); i++){
			guess(s2[i]); // 猜一个字母 
			if(win || lose) break; // 检查状态 
		}
		
		// 根据结果进行输出
		if(win) {
			puts("You win.");
		}else if(lose){
			puts("You lose.");
		}else{
			puts("You chickened out.");
		}
		
	}
	return 0;
}

