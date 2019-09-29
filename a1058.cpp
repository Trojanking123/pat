#include<cstdio>

const long long int gallon = 29*17;
const long long int sickle = 29;
int main(void)
{
  long long int a1,a2,a3;
  long long int b1,b2,b3;
  scanf("%lld.%lld.%lld %lld.%lld.%lld",&a1,&a2,&a3, &b1,&b2,&b3);
  long long int a = gallon*a1+sickle*a2+a3;
  long long int b = gallon*b1+sickle*b2+b3;
  
  long long int pay = b+a;
  
  
  printf("%lld.%lld.%lld",pay/gallon, pay%gallon/sickle, pay%sickle);
  
  return 0;
}