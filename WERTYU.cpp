#include<stdio.h>
#include<string.h>
char buf[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
	int c;
	while((c = getchar())!=EOF){
		int i;
		for(i = 0; buf[i] && buf[i]!=c ; i++) ;
		if(buf[i]) putchar(buf[i-1]);
		else putchar(c);
	}
}
