#include<stdio.h>
#include<ctype.h>
double a[26];



int main(){
	a['C' - 'A'] = 12.010;
	a['H' - 'A'] = 1.008;
	a['O' - 'A'] = 16.00;
	a['N' - 'A'] = 14.01;
	
	int t;
	scanf("%d", &t);
	char buf[81];
	while(t--){
		scanf("%s", buf);
		int s = 0;
		
		double sum = 0;
		
		while(buf[s]){
			double w = 0;
			if(buf[s]=='C') w += a['C'-'A'];
			else if(buf[s]=='H') w+= a['H'-'A'];
			else if(buf[s]=='O') w+= a['O'-'A'];
			else if(buf[s]== 'N') w+= a['N' - 'A'];
			
			s++;
			int shu = 0, q = 1;
			while(buf[s] && isdigit(buf[s])){
				shu = (buf[s]-'0')+ shu * q;
				s++;
				q*=10;
			}
			sum += ((shu == 0) ? 1 : shu )* w;
		}
		printf("%.3lf\n", sum);
	}

	return 0;
}
