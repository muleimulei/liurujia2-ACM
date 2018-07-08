#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
typedef vector<int> V;

V v;
//vector<string> vv;

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		v.clear();
		int m;
		scanf("%d", &m);
		for(int i = 0; i< m;i++){
			int num;
			scanf("%d", &num);
			v.push_back(num);
		}
		int w = 0;
		int s = v.size();
			for(int i = 0; i< 1000; i++){
				int c = v[0];
				for(int j = 0; j< s;j++){
					if(j== s-1){
						v[j] = abs(v[j] - c);
					}else{
						v[j] = abs(v[j+1] - v[j]);
//						ss+=v[i];
					}
				}
			}
			for(int j = 0; j< s;j++){
				if(v[j]==0) w++;
			}
			
//			printf("%s\n", ss.c_str());
			if(w==s){
				puts("ZERO");
//				break;
			}else{
				puts("LOOP");
//				break;
			}
	}
	return 0;
}
