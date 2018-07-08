#include<stdio.h>
#include<algorithm>
#include<string>
struct E{
	char name[100];
	int age;
	int score;
};

E buf[100];

bool cmp(E a, E b){
	if(a.score!=b.score) return a.score<b.score;

	int tmp = strcmp(a.name, b.name);
	if(tmp!=0){
		return tmp<0;
	}
	else{
		return a.age<b.age;
	}
}


int main4()
{
	int n;
	while(scanf("%d", &n)!=EOF){
		int i;
		for(i=0; i<n; i++){
			scanf("%s%d%d", &buf[i].name, &buf[i].age, &buf[i].score);	
		}

		std::sort(buf, buf+n, cmp);

		for(i=0; i<n; i++){
			printf("%s %d %d\n", buf[i].name, buf[i].age, buf[i].score);
		}
	}
	return 0;
}
