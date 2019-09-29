#include<cstdio>

int main(void)
{
	int sum = 0;
	int num[3] = {0};
	int n;
	scanf("%d",&n);

	do
	{
		num[sum++] = n%10;
		n = n/10;
	}while(n != 0);
	for(int i = 0; i < num[2]; i++)
	{
	  
		printf("B");
	}
	for(int i = 0; i < num[1]; i++)
	{
	
		printf("S");
	}
	for(int i = 0; i < num[0]; i++)
	{
	  
		printf("%d",i+1);
	}


	return 0;
}