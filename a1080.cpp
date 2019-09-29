
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;

struct Student{
    int ge;
    int gi;
    int grade;
    int app[5];
    int school = -1;
    int id;
    int rank;
}stu[40010];

bool equal(Student a, Student b){
    if(a.grade == b.grade && a.ge == b.ge) return true;
    else return false;
}
bool cmp(Student a, Student b){
    if(a.grade != b.grade) return a.grade > b.grade;
    else return a.ge >= b.ge;
}

vector<int>  admission[100];

int main(void){
    int n, m ,k;
    scanf("%d %d %d", &n, &m, &k);
    int quota[100];
    for(int i = 0; i < m; i++){
        scanf("%d", &quota[i]);
    }

    for(int i = 0; i < n; i ++){
        scanf("%d %d",&stu[i].ge,&stu[i].gi);
        for(int j = 0; j < k; j++){
            scanf("%d",&stu[i].app[j]);
        }
        stu[i].grade = stu[i].ge + stu[i].gi;
        stu[i].id = i;
    }
    sort(stu,stu+n,cmp);
    /*
    stu[0].rank = 0;
    for(int i = 1; i < n; i++){
        if( equal(stu[i], stu[i-1])) stu[i].rank = stu[i-1].rank;
        else stu[i].rank = i;
    }
    */
    //admission.resize(110);
    clock_t start, finish;
    start = clock();
    int limit[100]={0};
    for(int j = 0; j < k; j++){
        if( limit[ stu[0].app[j] ] < quota[ stu[0].app[j] ] ){
            admission[stu[0].app[j]].push_back(stu[0].id);
            limit[ stu[0].app[j] ]++;
            stu[0].school = stu[0].app[j];
            break;
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < k; j++){
            int choice = stu[i].app[j];
            if(limit[choice] < quota[choice] || ( stu[i].grade == stu[i-1].grade && stu[i].ge == stu[i-1].ge && stu[i-1].school == choice)  ){
                admission[choice].push_back(stu[i].id);
                limit[choice]++;
                stu[i].school = stu[i].app[j];
                break;
            }
        }
    }
    finish = clock();
    //printf("TIME: %ld\n",finish-start);
    start = clock();
    for(int i = 0; i < m; i++){
        if(admission[i].size()) {
            sort(admission[i].begin(), admission[i].end());
            int total = admission[i].size();
            for(int j = 0; j < total; j++){
                printf("%d",admission[i][j]);
                if(j != total - 1) printf(" ");
            }
            
        }
        printf("\n");
        
    }
    finish = clock();
    //printf("TIME: %ld\n",finish-start);
    return 0;
}



