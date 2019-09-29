#include<cstdio>
#include<cstring>
#include<algorithm>


using namespace std;

struct Student {
    char name[12];
    char id[12];
    int grade;
}stu[110];

bool cmp(Student a, Student b){
    return a.grade>b.grade;
}
int main(void){
    int n = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%s %s %d",stu[i].name, stu[i].id, &stu[i].grade);
    }

    int min, max;
    bool flag = false;
    scanf("%d %d",&min,&max);
    sort(stu,stu+n, cmp);
    for(int i = 0; i < n; i++){
        if(stu[i].grade <= max && stu[i].grade >= min){
            flag = true;
            printf("%s %s\n",stu[i].name, stu[i].id);
        }
    }
    if(flag == false) printf("NONE\n");


    return 0;
}