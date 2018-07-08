#include<stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		char buf[81];
		scanf("%s", buf);
		int l = 1;
		int s = 0;
		int sum = 0;
		while(buf[s]){
			if(buf[s] == 'O') {
				sum+= l;
				l++;
			}
			if(buf[s] == 'X') {
				l = 1;
			}
			s++;
		}
		printf("%d\n", sum);
	}
	return 0;
}
