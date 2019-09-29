#include<cstdio>

int main(void)
{
  int start[54];
  int end[54];
  int shuffle[54];
  int n;
  char map[5] = {'S','H','C','D','J'};
  scanf("%d",&n);
  for(int i = 0; i < 54; i++)
  {
    start[i] = i;
    end[i] = i;
  }
  for(int i = 0; i < 54; i++)
  {
    scanf("%d", shuffle + i);
  }
  while(n--)
  {
    for(int i = 0; i<54; i++)
    {
      end[shuffle[i]-1] = start[i];
    }
    for(int i = 0; i<54; i++)
    {
      start[i] = end[i];
    }
  }
  for(int i = 0; i<54; i++)
  {
    printf("%c%d", map[start[i]/13],start[i]%13+1);
    if(i != 53)
    {
      printf(" ");
    }
  }
  return 0;
}