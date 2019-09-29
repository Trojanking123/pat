#include<cstdio>
#include<math.h>
int main(void)
{
  int n,line;
  char c;
  scanf("%d%c%c",&n,&c,&c);
  line = sqrt((n-1)/2+1);
  
  for(int i = line; i>=1;i-- )
  {
    for(int j = 0;j<line-i; j++)
    {
      printf(" ");
    }
    for(int j = 0; j < i*2-1;j++)
    {
      printf("%c",c);
    }
    printf("\n");
  }
  for(int i = 2;i<=line; i++)
  {
    for(int j = 0; j<line-i;j++)
    {
      printf(" ");
    }
    for(int j = 0; j<2*i-1;j++)
    {
      printf("%c",c);
    }
    printf("\n");
  }
  printf("%d",n-(line*line*2-1));
  return 0;
}