#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int main(){
	int n;
	while(scanf("%d", &n)!=EOF && n){
		int cnt = 0;
		for(int fghij = 1234; ; fghij++){
			int abcde = fghij * n;
			char buf[100];
			sprintf(buf, "%05d%05d", abcde, fghij);
			if(strlen(buf)>10) break;
			sort(buf, buf+10);
			if(strcmp(buf, "0123456789")!=0) continue;
			cnt++;
			printf("%05d / %05d = %d\n", abcde, fghij, n);
		}
		if(!cnt) printf("There are no solutions for %d.\n", n);
		
		printf("\n");
	}
	return 0;
}

