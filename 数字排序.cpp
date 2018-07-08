#include<stdio.h>
#include<algorithm>

bool cmp(int a, int b){
	return a> b;
}

int main2()
{
	int n;
	int buf[100];
	while(scanf("%d", &n)!=EOF){
		int i;
		for(i=0; i<n;i++){
			scanf("%d", &buf[i]);
		}

		std::sort(buf, buf+n, cmp);
		for(i=0; i<n;i++){
			printf("%d ", buf[i]);
		}
		printf("\n");

	}
	return 0;
}


int main1()
{
	int n;
	int buf[100];
	while(scanf("%d", &n)!=EOF){
		int i,j;
		for(i=0; i<n;i++){
			scanf("%d", &buf[i]);
		}

		for(i=0; i<n;i++){
			for(j=0; j<n-1-i; j++){
				if(buf[j] > buf[j+1] ){
					int tmp = buf[j+1];
					buf[j+1] = buf[j];
					buf[j] = tmp;

				}
			}
		}

		for(i=0; i<n;i++){
			printf("%d ", buf[i]);
		}
		printf("\n");
	}
	return 0;
}