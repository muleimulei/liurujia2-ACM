#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 64 + 10;
char buf[maxn][maxn];
int n, totblack = 0;

vector<int> tot, v1;

vector<int> tentofive(int s){ // 十进制转5进制 
	vector<int > v;
	int t = s;
	while(t!=0){
		v.push_back(t % 5);
		t /= 5;
	}
	if(s==0) v.push_back(0);
	return  v;
}

int fivetoten(vector<int > v){
	int sum = 0;
	for(int i = v.size()-1; i>=0; i--){
		sum =  sum *5 + v[i]; 
	}
	return sum;
}

bool judge(int x, int y, int w){
	if(w==1) return false;
	for(int s = x+1; s -x+1 <= w; s++){
		for(int s1 = y; s1 - y + 1<=w; s1++){
			if(buf[s][s1] != buf[x][s1] || buf[x][y] != buf[s][s1]) return true;
		}
	}
	return false;
}

void dfs(int x, int y, int w, vector<int> e){
	if(judge(x, y, w)){
		e.push_back(1);
		dfs(x, y, w/2, e);
		e.pop_back();
		
		e.push_back(2);
		dfs(x, y+w/2, w/2, e);
		e.pop_back();
		
		e.push_back(3);
		dfs(x+w/2, y, w/2, e);
		e.pop_back();
		
		e.push_back(4);
		dfs(x+w/2, y+w/2, w/2, e);
		e.pop_back();
	}else{
		if(buf[x][y]=='1'){
			totblack++;
			tot.push_back( fivetoten(e) );
		}
	}
}

void draw(int x, int y, int w, vector<int> &f, int i){
	if(i<f.size()&&f[i]==0){
		memset(buf, '*', sizeof(buf));
		return;
	}
	if(i==f.size() ){
		for(int c = x; c-x+1<=w; c++){
			for(int v = y; v-y+1<=w; v++){
				buf[c][v]='*';
			}
		}
		return;
	}
	if(f[i]==1){
		draw(x, y, w/2, f, i+1);
	}else if(f[i]==2){
		draw(x, y+w/2, w/2, f, i+1);
	}else if(f[i]==3){
		draw(x+w/2, y, w/2, f, i+1);
	}else if(f[i]==4){
		draw(x+w/2, y+w/2, w/2, f, i+1);
	}
}

void show(){
	for(int i = 0; i<n;i++){
		for(int j = 0; j<n;j++){
			putchar(buf[i][j]);
		}
		printf("\n");
	}
}

int main(){
	
	
	int kase = 0;
	while(scanf("%d", &n)!=EOF && n){
		if(kase) printf("\n");
		printf("Image %d\n", ++kase);
		if(n>0){
			tot.clear();
			v1.clear();
			totblack = 0;
			for(int i = 0; i < n; i++){
				char c[70];
				scanf("%s", c);
				strcpy(buf[i], c);
			}
			dfs(0, 0, n, {});
			
			if(tot.size()){
				sort(tot.begin(), tot.end());
//				int k = 0;
				for(int i = 0; i<tot.size(); i++){
					if(i % 12==0) printf("%d", tot[i]);
					else printf(" %d", tot[i]);
					if((i+1) % 12==0) printf("\n");
				}
				if(tot.size() % 12) printf("\n");
			}
			printf("Total number of black nodes = %d\n",totblack);
		}else{
			memset(buf, '.', sizeof(buf));
			n = -n;
			int x;
			vector<int> f;
			while(scanf("%d", &x)!=EOF&&x!=-1){
				f = tentofive(x);
				draw(0, 0, n, f, 0);
				
//				printf("%d\n", x);
//				show();
//				printf("\n");
			}
			show();
		}
	}
	
	return 0;
} 
