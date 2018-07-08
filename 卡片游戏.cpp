#include<cstdio>
#include<list>
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n)==1 && n){
		list<int> l;
		for(int i = 1; i<=n;i++){
			l.push_back(i);
		}
		printf("Discarded cards:");
		while(l.size()>1){
			int p = l.front();
			l.pop_front();
			int m = l.front();
			l.pop_front();
			l.push_back(m);
			if(l.size()==1){
				printf(" %d", p);
			}else{
				printf(" %d,", p);
			}
		}
		printf("\nRemaining card: %d\n", l.front());
	}
	return 0;
}
