#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

struct rich{
    char name[9];
    int age;
    int net;
}p[100010];

bool cmp(rich a, rich b){
    if(a.net != b.net) return a.net > b.net;
    else if(a.age != b.age) return a.age < b.age;
    else return strcmp(a.name, b.name) < 0;
}

int main(void) {
    int n, query;
    scanf("%d %d", &n, &query);

    for(int i = 0; i < n; i++){
        scanf("%s %d %d", p[i].name, &p[i].age, &p[i].net);
    }

    sort(p, p+n, cmp);

    int m = 0, min, max, count = 0; 
    for(int i = 0; i < query; i++){
        count=0;
        scanf("%d %d %d", &m, &min, &max);
        printf("Case #%d:\n", i+1);
        for(int j = 0; j < n && count < m; j++){
            if(p[j].age >= min && p[j].age <= max ){
                //cout << min<< " "<< max;
                printf("%s %d %d\n",p[j].name, p[j].age, p[j].net);
                count++;
            }
        }
        if(count == 0){
            printf("None\n");
        }
    }
    return 0;
}
