#include<stdio.h>

bool isyeap(int x){
	if(x%4==0 && x%100!=0 || x % 400 ==0){
		return true;
	}else{
		return false;
	}
}

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
		if(day> dayofmonth[month][isyeap(year)]){   // 若日数超过了当月最大日数
			day=1;
			month++; // 进入下一月
			if(month>12){  // 超过12
				month=1;
				year++;
			}
		}
	}
};

int buf[5001][13][33];

int abs(int x){
	return x<0? -x : x;
}


int maina()
{
	Date date;

	date.year = 0;
	date.month = 1;
	date.day = 1;

	int cnt = 0; // 天数技数
	
	while(date.year!=5000){
		buf[date.year][date.month][date.day] = cnt;
		date.nextday();
		cnt++;
	}

	int d1, m1, y1;
	int d2, m2, y2;
	
	while(scanf("%4d%2d%2d", &y1, &m1, &d1)!=EOF){
		scanf("%4d%2d%2d", &y2, &m2, &d2);
		printf("%d\n", abs(buf[y1][m1][d1]-buf[y2][m2][d2])+1);
	}

	return 0;

}