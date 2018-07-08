#include<stdio.h>
#include<string.h>
#include<ctype.h>

const char *env = "A   3  HIL J M O   2TUVWXY51SE Z  8 ";
const char *msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrowed palindrome" };

char r(char c){
	if(isalpha(c)){
		return env[c - 'A'];
	}else{
		return env[c - '0' + 25];
	}
}

int main()
{
	char s[30];
	while(scanf("%s", s) == 1){
		int len = strlen(s);
		int p = 1, m = 1;
		for(int i = 0; i < (len + 1)/ 2; i++){
			if(s[i] != s[len-1-i]) p = 0;
			if(r(s[i])!= s[len-1-i]) m = 0;
		}
		printf("%s -- %s.\n\n", s, msg[2*p+m]);
	}
	return 0;
}
