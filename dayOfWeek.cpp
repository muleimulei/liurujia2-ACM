#include<stdio.h>
#include<string.h>
#define ISYEAP(x) x%4==0 && x % 100 !=0 || x % 400 ==0 ? 1:0

int dayofmonth[13][2]={
	{0, 0},
	{31, 31},
	{28, 29},
	{31, 31},
	{30, 30},
	{31, 31},
	{30, 30},
	{31, 31},
	{31, 31},
	{30, 30},
	{31, 31},
	{30, 30},
	{31, 31}
};


struct Date{
	int year;
	int month;
	int day;

	void nextday(){
		day++;
		if(day> dayofmonth[month][ISYEAP(year)]){   // 若日数超过了当月最大日数
			day=1;
			month++; // 进入下一月
			if(month>12){  // 超过12
				month=1;
				year++;
			}
		}
	}
};

int buf[3001][13][32];

char monthname[13][20]={
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

char weekname[7][20]={
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
};

int main6()
{
	Date date;

	int cnt = 0;
	date.year = 0;
	date.month = 1;
	date.day = 1;


	while( date.year != 3000 ){
		buf[date.year][date.month][date.day] = cnt;
		date.nextday();
		cnt++;
	}

	int y,m,d;
	char s[20];

	while(scanf("%d%s%d", &d, s, &y)!=EOF){
		for(m=1; m<=12; m++){
			if(strcmp(s, monthname[m])==0) break;
		}
		int days = buf[y][m][d] - buf[2012][7][16];

		days+=1;

		puts(weekname[(days%7 + 7) % 7]);
	}
	return 0;
}