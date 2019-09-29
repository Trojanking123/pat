#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct record
{
	char name[25];
	int month;
	int day;
	int hour;
	int minute;
	char line[10];
}re[1010];


double rate[24];
double one_day = 0;
bool cmp(record a, record b)
{
	if(strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) < 0;
	else if(a.month != b.month) return a.month < b.month;
	else if(a.day != b.day) return a.day < b.day;
	else if(a.hour != b.hour) return a.hour < b.hour;
	else if(a.minute != b.minute) return a.minute < b.minute;
}

double cal(record a, record b)
{
	double cost = 0;
	while(a.day<b.day || a.hour<b.hour || a.minute < b.minute)
	{
		cost += rate[a.hour];
		a.minute++;
		if(a.minute == 60)
		{
			a.minute = 0;
			a.hour++;
		}
		if(a.hour == 24)
		{
			a.hour = 0;
			a.day++;
		}
	}
	
	return cost/100;
}
int time(record a, record b)
{
	int t = 0;
	while(a.day<b.day || a.hour<b.hour || a.minute < b.minute)
	{
		t++;
		a.minute++;
		if(a.minute == 60)
		{
			a.minute = 0;
			a.hour++;
		}
		if(a.hour == 24)
		{
			a.hour = 0;
			a.day++;
		}
	}
	return t;
}


int main(void)
{
	

	int n;

	for(int i = 0; i < 24; i++)
	{
		scanf("%lf", &rate[i]);
	}

	for(int i = 0; i < 24; i++)
	{
		one_day += rate[i];
	}
	one_day *= 60;
	

	scanf("%d", &n);
	record temp;
	for(int i = 0; i < n; i++)
	{
		scanf("%s %d:%d:%d:%d %s", temp.name, &temp.month, &temp.day, &temp.hour, &temp.minute, temp.line);
		re[i]  = temp;
	}
	sort(re, re+n, cmp);

	record last;
	last.name ;
	double total = 0;
	int flag = 0;
	for(int i = 0; i < n; i++)
	{
		record now = re[i];
		record next = re[i+1];
		if(strcmp(now.name, last.name) != 0)
		{

			

			total = 0;
			flag = 0;
		}
		if(strcmp(now.name, next.name) != 0)
		{
			last = now;
			if(total != 0.0)
			{
				printf("Total amount: $%.2f\n", total);
			}
			
			
			continue;
		}
		if(strcmp(now.line, next.line) > 0)
		{
			flag++;
			if(flag == 1)
			{
				printf("%s %02d\n", now.name, now.month);
			}
			int m = time(now, next);
			if(cal(now, next) != 0)
			{
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", now.day,now.hour, now.minute, next.day, next.hour, next.minute, m, cal(now, next));
			}
			
			total += cal(now, next);
		}
		last = now;
	}
	



	return 0;
}