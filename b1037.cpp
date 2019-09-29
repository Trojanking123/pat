#include<cstdio>

const int gallon = 29*17;
const int sickle = 29;
int main(void)
{
  int a1,a2,a3;
  int b1,b2,b3;
  scanf("%d.%d.%d %d.%d.%d",&a1,&a2,&a3, &b1,&b2,&b3);
  int a = gallon*a1+sickle*a2+a3;
  int b = gallon*b1+sickle*b2+b3;
  
  int pay = b-a;
  
  if(pay < 0)
  {
    printf("-");
    pay = -pay;
  }
  printf("%d.%d.%d",pay/gallon, pay%gallon/sickle, pay%sickle);
  
  return 0;
}