
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxK = 6;
const int maxN = 10010;
const int maxM = 100010;
int goal[maxK] = {0};
struct user{
    int id;
    int total_grade;
    int score[maxK]={-2,-2,-2,-2,-2,-2};
    bool flag;
}p[maxN];

int get_perfect(struct user a){
    int sum=0;
    for(int i = 1; i <= maxK; i++){
        if(a.score[i] == goal[i]) sum++;
    }
    return sum;
}

bool cmp(struct user a, struct user b){
    if(a.total_grade != b.total_grade) return a.total_grade > b.total_grade;
    else if(get_perfect(a) != get_perfect(b)) return get_perfect(a) > get_perfect(b);
    else return a.id < b.id;
}

int main(void){
    int n, k, m;
    scanf("%d %d %d",&n, &k, &m);

    for(int i = 1; i <= k; i++){
        scanf("%d",goal+i);
    }

    int id, num, get;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d",&id,&num,&get);
        p[id].id = id;
        if(p[id].score[num] < get) p[id].score[num]=get;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(p[i].score[j] >=0 ) p[i].total_grade += p[i].score[j];
        }
    }
    
    sort(p+1, p+n+1, cmp);
    
    int r = 1;
    int last = 0;
    p[0].total_grade = -10;
    for(int i = 1; i <= n; i++){
        if(p[i].total_grade != 0) {
            p[i].flag = true;
        }else {
            for(int j = 1; j <= k; j++){
                if(p[i].score[j] ==0 ) p[i].flag = true;   
            }
        }
    }

    for(int i = 1; i <= n && p[i].flag==true; i++){
        if(p[i].total_grade != p[last].total_grade)  r=i, printf("%d ",r);
            else printf("%d ",r);
        printf("%05d %d", p[i].id, p[i].total_grade);

        for(int j = 1; j <= k; j++){
            //printf(" %d", p[i].score[j]);
            if(p[i].score[j] >=0 ) printf(" %d", p[i].score[j]);
            else if(p[i].score[j] == -1) printf(" 0");
            else printf(" -");
        }
        last = i;
        printf("\n");
    }
}

