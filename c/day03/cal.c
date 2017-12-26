/*
isleep:判断给定年份是否为闰年
year:待判断的年份
return value:
	0 	no
	1	yes
 */
int isleap(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	//return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 1 : 0;
}

/*
daysofmonth:判断任意一个月份有多少天 
month:待计算的月份
year:month所属的年份
return value:
	month月有多少天
 */
int daysofmonth(int month, int year)
{
#if 0
	int day;

	switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			day = 31;		
			break;
		case 4: case 6: case 9: case 11:
			day = 30;	
			break;
		case 2:
			day = 28 + isleep(year);
			break;
		default:
			day = -1;
			break;
	}

	return day;
#endif
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	arr[2] += isleap(year);

	return days[month];
}

/*
 定义一个函数,求得给定年月日是星期几,已知1990.1.1是星期一,给定的年份一定大于等于1990
year, month, day:带计算的日期
return value:
	星期几
 */

int dayofweek(int year, int month, int day)
{
	int sum = 0;

	//year/month/day距离1990.1.1有多少天
	for (int i = 1990; i < year; i++) {
		sum += (365 + isleap(i));
	}	

	for (int i = 1; i < month; i++) {
		sum += daysofmonth(i, year);	
	}

	sum += day;

	return sum % 7;
}



