#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

struct student
{
	int id;
	int rank[4];
	int score[4];
}stu[2050];
int now = 0;
bool cmp(student a, student b)
{
	return a.score[now]>b.score[now];
}
int info[1000000][4] = {0};

int main(void)
{
	//funtype f[4] = {cmp_a,cmp_c, cmp_m, cmp_e};

	char code[6] = {"ACME"};
	int n, m;
	scanf("%d%d", &n, &m);
	student temp;
	for(int i =0; i < n; i++)
	{
		scanf("%d%d%d%d", &temp.id,temp.score+1, temp.score+2, temp.score+3);
		temp.score[0] = (temp.score[1]+temp.score[2]+temp.score[3])/3;
		stu[i]=temp;

	}
	for(int i = 0; i < 4; i++)
	{
		now = i;
		sort(stu, stu+n, cmp);
		stu[0].rank[i] = 1;
		info[stu[0].id][i] = 1;
		for(int j = 1; j < n; j++)
		{
			if(stu[j].score[i] == stu[j-1].score[i])
			{
				stu[j].rank[i] = stu[j-1].rank[i];
			}else
			{
				stu[j].rank[i] = j+1;
			}
			info[stu[j].id][i] = stu[j].rank[i];
		}
	}
	int query;
	for(int i = 0; i<m; i++)
	{
		int k = 0;

		scanf("%d", &query);
		if(info[query][0] == 0)
		{
			printf("N/A\n");
		}else
		{
			for(int j = 0; j < 4; j++)
			{
				if(info[query][j] < info[query][k])
				{
					k=j;
				}
			}
			printf("%d %c\n",info[query][k], code[k]);
		}
	}

	return 0;
}































