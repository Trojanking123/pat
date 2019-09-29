#include<cstdio>
#include<cstring>
int main(void)
{
	char num[1002];
	int count[10] = {0};
	gets(num);
	for(int i = 0; i < strlen(num); i++)
	{
		count[num[i] - '0']++;
	}

	for(int i = 0; i < 10; i++)
	{
		if(count[i] != 0)
		{
			printf("%d:%d\n",i,count[i]);
		}
	}

	return 0;
}