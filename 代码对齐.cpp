#include<cstdio>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;
vector<string> v[1000+10];
char buf[1000 + 10];

int cols = 0;
int colmax[1000]={0};

void print(string s, int len, char c){
	printf("%s", s.c_str());
	for(int i = s.size(); i< len; i++){
		printf("%c", c);
	}
}
int main(){
	int row = 0;
	while(fgets(buf, sizeof(buf), stdin)!=NULL){
		stringstream ss(buf);
		string str;
		int i = 0;
		while(ss>> str){
			v[row].push_back(str);
			int size = str.size();
			colmax[i] = max(colmax[i], size);
			i++;
		}
		cols = max(i, cols);
		row++;
	}
	
	
	
	for(int i = 0; i< row; i++){
		int size = v[i].size();
		for(int j = 0; j < size; j++){
			if(j == size-1){
				 printf("%s", v[i][j].c_str()); break;
			}
			int max = colmax[j];
			print(v[i][j], max+1, ' ');
		}
		printf("\n");
	}
	
//	printf("%d %d\n",row, cols);
	
	return 0;
}
