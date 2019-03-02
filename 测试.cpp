#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<cstdio>
#include<string.h>
#include<vector>
#include<set>
#include<list>
#include<iostream>
#include<sstream>
#include<queue>
#include<deque>
#include<cctype>

using namespace std;

//int a,b,c;
int is_prime(int n){ //≈–∂œ «∑Ò «Àÿ ˝ 
	if(n<=1) return 0;
	int m = floor(sqrt(n) + 0.5);
	for(int i = 2; i<=m;i++){
		if(n % i ==0) return 0;
	}
	return 1;
}

long long  C(int n, int m){
	if(m < n-m) m = n-m;
	long long ans = 1;
	for(int i = m+1; i<=n; i++) ans *= i;
	for(int i = n-m; i>2; i--) ans /= i;
	return ans;	
}

int cc(int *a){
	printf("%d\n", sizeof(a));
}

void doit(int i){
	if(i !=0){
		doit(i / 2);
		printf("%d ", i %2);
	}
}

struct edge{
	int val, e;
	edge (int val, int e): val(val), e(e){
	}
	bool operator < (const edge &b) const{
		return val > b.val;
	}
};

int main()
{
	priority_queue<edge> v;
	v.push({4, 2});
	v.push({5, 3});
	v.push({2, 6});

	while(!v.empty()){
		printf("%d ", v.top().val);
		v.pop();
	}
	return 0;
}
