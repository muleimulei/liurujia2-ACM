#include<cstdio>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
int a[]={2,3,5};

int main(){
	priority_queue<ll,vector<ll> ,greater<ll> > pq;
	set<ll> s;
	
	s.insert(1);
	pq.push(1);
	
	for(int i = 1;;i++){
		
		ll n = pq.top();
		pq.pop();
		
		if(i==1500){
			printf("The 1500'th ugly number is %lld.\n", n);
			break;
		}
		for(int i = 0; i< 3;i++){
			int x = a[i];
			if(!s.count(x * n)){
				pq.push(x * n);
				s.insert(x * n);
			}
		}
		
	} 
	return 0;
}
