#include<stdio.h>
#include<map>
using namespace std;
char buf[51][1001];

char findchar(map<char, int> &mm,int &count){
	map<char, int>::iterator beg = mm.begin(), end = mm.end(), pos1,pos2;
	pos1 = pos2 = beg;
	pos2++;
	char c;
	while(pos2!=end){
		int t = pos2->second;
		if(t>pos1->second){
			pos1 = pos2;
		}
		else if(t == pos1->second){
			if(pos2->first < pos1->first){
				pos1 = pos2;
			}
		}
		pos2++;
	}
	c = pos1->first;
	pos2 = beg;
	while(pos2!=end){
		if(pos2->first!=c){
			count+=pos2->second;
		}
		pos2++;
	}
	return c;
}

int main(){
	int t;
	scanf("%d", &t);
	map<char, int> mm;
	while(t--){
		int m, n;
		scanf("%d %d", &m, &n);
		
		char ans[n];
		int count = 0,pos=0;
		
		for(int i = 0; i<m;i++){
			scanf("%s", buf[i]);
		}
		
		for(int l = 0; l<n;l++){
			mm.clear();
			for(int h = 0; h<m;h++){
				char c = buf[h][l];
				mm[c]++; // 计算出该列AGCT的数目 
			}
			char c = findchar(mm, count);
			ans[pos++] = c; 
		}
		
		for(int i = 0; i<n;i++){
			printf("%c", ans[i]);
		}
		printf("\n%d\n", count);

	}
	return 0;
} 
