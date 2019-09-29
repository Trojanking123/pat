#include <cstdio>

int main(void)
{
  char result[3] = {'W','T','L'};
  double odd[3][3];
  int k = 0;
  double max[3]={0};
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      scanf("%lf",&odd[i][j]);
    }
  }
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(odd[i][j] >= max[i])
      {
        k = j;
        max[i] = odd[i][j];
      }
    }
    printf("%c ",result[k]);
  }
  printf("%.2f",(max[0]*max[1]*max[2]*0.65-1)*2);
  
  
  return 0;
}