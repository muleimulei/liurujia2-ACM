#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std; 

const int maxcol = 60;



// 输出字符串，输出字符串s，长度不足len时补字符extra
void print(string s, int len, char c){
	cout<<s;
	for(int i = 0; i< len - s.size(); i++){
		cout<<c;
	}
} 

int main()
{
	int n;
	while(cin>>n){
		vector<string> names;
		scanf("%d", &n);
		int maxlen = 0;
		while(n--){
			string n;
			cin>>n;
			names.push_back(n);
			maxlen = max(maxlen, (int)n.size());
		}
		int num = names.size();
		// 计算行列
		int l = (maxcol - maxlen) / (maxlen+2) + 1, h = 0;
		h = num / l;
		if(num % l !=0) h++;
		print("-", 60, '-');
		cout<<endl;
		sort(names.begin(), names.end());
		
		for(int i = 0; i< h; i++){
			
			for(int j = 0; j< l; j++){
				
				int z = j * h + i;
				if(z < num){
					if(j == l-1){
					print(names[z], maxlen+2, ' ');
					break;
				}
				else {
					print(names[z], maxlen, ' ');
				}
				}
			}
			printf("\n");
		}
	}
	
	
	return 0;
}
