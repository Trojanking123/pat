#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct people
{
	char id[10];
	int m;
	int v;
	int sum;
	int type;
}p[100010];

bool cmp(people a, people b)
{
	if(a.type != b.type)
	{
		return a.type < b.type;
	}
	else if(a.sum != b.sum)
	{
		return a.sum>b.sum;
	}
	else if(a.m != b.m)
	{
		return a.m>b.m;
	}
	else
	{
		return strcmp(a.id,b.id)<0;
	}
}



int main(void)
{
	int num = 0;
	int n,l,h;
	scanf("%d %d %d", &n,&l,&h);
	people temp;
	for(int i = 0; i < n; i++)
	{
		scanf("%s %d %d",temp.id, &temp.m, &temp.v);
		if(temp.m < l || temp.v < l) continue;
		temp.sum = temp.m+temp.v;
		if(temp.m >= h && temp.v >= h) temp.type = 1;
		else if(temp.m >= h && (temp.v >= l && temp.v < h)) temp.type = 2;
		else if(temp.m >= l && temp.m < h && temp.v >= l && temp.v < h && temp.m >= temp.v) temp.type = 3;
		else temp.type = 4;
		p[num++] = temp;
	}

	sort(p, p+num, cmp);
	printf("%d\n",num );
	for(int i = 0; i < num; i++)
	{
		printf("%s %d %d\n",p[i].id, p[i].m, p[i].v);
	}

	return 0;
}