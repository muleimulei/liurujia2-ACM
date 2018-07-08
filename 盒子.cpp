#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;

struct rect{
	int w,l;
} v[6];

bool cmp(rect &r1, rect &r2){
	return r1.w < r2.w || (r1.w == r2.w && r1.l < r2.l);
}

int main(){
	set<int> s1, s2;
	int w,h;
	
	int n = 0;
	while(scanf("%d %d", &w, &h)!=EOF){
		if(w>h){
			swap(w, h);
		}
		v[n].w = w;
		v[n++].l = h;
		
		if(n==6){
			n = 0;
			sort(v, v+6, cmp);
			int flag = 1;
			for(int i = 0; i<6; i+=2){
				if(v[i].w != v[i+1].w || v[i].l != v[i+1].l) flag = 0;
			}
			if(v[0].w != v[2].w || v[0].l != v[4].w || v[2].l != v[4].l) flag = 0;
			
			if(flag){
				puts("POSSIBLE");
			}else{
				puts("IMPOSSIBLE");
			}
		}
	}
	
	return 0;
} 
