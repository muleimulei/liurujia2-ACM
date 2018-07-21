#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int n,l, tot;


bool judge(string s, char c){
	string ss = s + c;
	int len = ss.size();
	if(len==1) return true;
	
	
	for(int c = 1; c <= len /2 ;c++){
		
		int i = 0;
		int j = len-1;
		while(i<c){
			if(ss[j]!=ss[j-c]){
				break;
			}
			i++;
			j--;
		}
		if(i == c) return false;
	}
	return true;
}

void dfs(string s, int num){
	if(tot==n){
		int p = 0;
		int len  =s.size();
		for(int i = 0; i < len; i++){
			printf("%c", s[i]);
			p++;
			if( (i+1) % 64 !=0  && p==4){
				if(i+1 != len){
				
				 printf(" ");
				 p = 0;
			}
			}
			if((i+1) % 64==0) {
				printf("\n");
				p = 0;
			}
		}
		if(len % 64 !=0) printf("\n");
		printf("%d\n", len);
		return;
	}else{
		for(char c = 'A'; c < 'A' + l; c++){
			if(judge(s, c)){
				s = s+c;
				num++;
				tot++;
//				printf("µÚ %d %s %d\n",num, s.c_str(), s.size());
				dfs(s, num); 
				s.resize(s.size()-1);
				if(tot == n) return;
//				printf("---µÚ %d %s %d---\n",num, s.c_str(), s.size());
			}
		}
	}
}

int main(){
	#ifdef LOCAL
		freopen("1.txt", "w+", stdout);
	#endif
	while(scanf("%d %d", &n,&l )==2){
		if(n==0 && l==0) break;

		int num = 0;
		tot = 0;
		string s = "";
		dfs(s, num);
	}
	return 0;
}
