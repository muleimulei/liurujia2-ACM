#include<cstdio>
#include<sstream>

bool read_input(int &w){
	int w1, d1, w2, d2;
	scanf("%d %d %d %d", &w1, &d1, &w2, &d2);
	bool b1 = true, b2 = true;
	
	if(w1==0){
		b1 = read_input(w1);
	}
	if(w2==0){
		b2 = read_input(w2);
	}
	w = w1+w2;
	return b1&&b2&&(w1 * d1 == w2*d2);
}

int main(){
	int n, w;
	scanf("%d", &n);
	while(n--){
		if(read_input(w)){
			puts("YES");
		}else{
			puts("NO");
		}
		if(n) printf("\n");
	}
	return 0;
}
