#include<cstdio>
#include<string.h>
int main(void)
{
  const int max = 81;
  char s[max];
  scanf("%s",s);
  int n = strlen(s);
  int line = (n+2)/3;
  for(int i = 0; i < line-1; i++)
  {
    printf("%c",s[i]);
    for(int j = 0; j<n-line*2;j++)
    {
      printf(" ");
    }
    printf("%c\n",s[n-1-i]);
  }
  for(int i = line-1; i<n-line+1;i++)
  {
    printf("%c",s[i]);
  }
  printf("\n");
  
  return 0;
}