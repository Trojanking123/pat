#include<cstdio>

#include<cstring>

void reverse(char *str)
{
	char *p = str + strlen(str)-1;
	char temp;
	while(str<p)
	{
		temp=*p, *p--=*str, *str++=temp;
	}
	
}
int main(void)
{
	char str1[105] , str2[105];
	char code[15] = {"0123456789JQK"};
	char result[105];

	scanf("%s %s", str1, str2);
	int n1 = strlen(str1);
	int n2 = strlen(str2);

	reverse(str1);
	reverse(str2);
	
	for(int i = n1; i < 105; i++)
	{
		str1[i] = '0';
	}
	for(int i = n2; i < 105; i++)
	{
		str2[i] = '0';
	}
	int n = n1>n2 ? n1:n2;
	for(int i = 0; i < n; i++)
	{
		if(i%2 == 0)
		{
			result[i] = code[(str1[i]+str2[i]-'0'-'0')%13];
		}
		else
		{
			int a = str2[i]-str1[i];
			if(a<0) a = 10+a;
			result[i] = code[a];
		}
	}
	result[n] = '\0';
	reverse(result);
	printf("%s\n", result);
	return 0;
}