#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int main(){
	int k;
	while(scanf("%d", &k)!=EOF){
		vector<pair<int, int>> v;
		for(int y = 1; y<= 2 * k; y++){
			if(y-k<=0) continue;
			double x = k * y * 1.0 / (y - k);
 			if(x== floor(x)){
				v.push_back(make_pair((int)x, y));
			}
		}
		printf("%d\n", v.size());
		for(int i =0 ; i<v.size();i++){
			pair<int , int> p = v[i];
			
			printf("1/%d = 1/%d + 1/%d\n", k, p.first, p.second);
		}
	}
	return 0;
} 


