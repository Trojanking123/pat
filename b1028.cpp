#include<cstdio>
struct Info
{
  int year;
  int month;
  int day;
  char name[6];
}min, max, temp;
int less(int year1,int month1, int day1, int year2, int month2,int day2)
{
  if((year1 < year2) || ((year1 == year2) && (month1<month2)) || ((year1 ==year2)&&(month2 == month1)&&(day1<=day2))   )
  {
    return 1;
  }
  return 0;
}

int juge(int year, int month, int day)
{
  
  if( less(year,month,day,2014,9,6) && less(1814,9,6, year,month, day)) return 1;
  return 0;
}

int main(void)
{
  
  int n,count = 0;
  min.year = 2014;
  min.month = 9;
  min.day = 6;
  max.year = 1814;
  max.month = 9;
  max.day = 6;
  scanf("%d",&n);
  while(n--)
  {
    scanf("%s %d/%d/%d",temp.name,&temp.year,&temp.month,&temp.day);
    if(juge(temp.year,temp.month,temp.day))
    {
      
      count++;
      if(less(max.year, max.month, max.day, temp.year, temp.month, temp.day))
      {
        max = temp;
      }
      if (less(temp.year, temp.month, temp.day, min.year, min.month, min.day))
      {
        min = temp;
      }
    }
  }
  if(count == 0) printf("0");
  else printf("%d %s %s",count, min.name,max.name);
  return 0;
}