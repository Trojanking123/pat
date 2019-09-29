#include <cstdio>
int main()
{
  int n = 0,col;
  char c;
  scanf("%d%c%c",&n,&c,&c);
  if(n%2)
  {
    col = (n+1)/2;
  }
  else col = n/2;
  col = col-2;
  for(int i = 0; i<n; i++)
  {
    printf("%c",c);
  }
  printf("\n");
  for(int i = 0; i<col; i++)
  {
    printf("%c",c);
    for(int j = 0; j<n-2;j++)
    {
      printf(" ");
    }
    printf("%c\n",c);
  }
  for(int i = 0; i<n; i++)
  {
    printf("%c",c);
  }
  return 0;
}