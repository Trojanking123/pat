#include<iostream>
#include<vector>
#include<set>
#include<algorithm>


using namespace std;
const int kMAX = 10000;
struct Node{
    int id;
    int area;
    int estate;
};

struct Family{
    int id;
    int num;
    double estate;
    double area;
    int flag ;
};

int father[kMAX];
int visited[kMAX];

Node all[kMAX];
Family res[kMAX];
set<int> counter;

int n;

bool cmp(Family a, Family b){
    if(a.flag != b.flag) return a.flag > b.flag;
    double avg_a = a.area/a.num;
    double avg_b = b.area /b.num;
    if(avg_a != avg_b) return avg_a > avg_b;
    else return a.id < b.id;
}


int findFather(int x){
    if(x == father[x]) return x;
    else{
        int f = findFather( father[x] );
        father[x] = f;
        return f;
    }
}

void Union(int a, int b){
    if(a == -1 || b == -1) return;
    a = findFather(a);
    b = findFather(b);
    if(a > b) father[a] = b;
    else father[b] = a;
}

int main(void){
    for(int i = 0; i < kMAX; i++){
        father[i] = i;
        res[i].id = i;
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        int f,m,k, id;
        cin >> id >> f >> m >> k;
        visited[id] = true;
        if(f != -1){
            Union(f, id);
            visited[f] = true;
        }
        if(m != -1){
            Union(m, id);
            visited[m] = true;
        }
        for(int j = 0; j < k; j++){
            int temp;
            cin >> temp;
            Union(temp, id);
            visited[temp] = true;
        }
        cin >> all[id].estate;
        cin >> all[id].area;
        all[id].id = id;
    }
    for(int i = 0; i < kMAX; i++){
        if(visited[i]){
            int f = findFather(i);
            
            res[f].num++;
            //printf("father:%d ,i:%d\n", f, i);
            res[f].area += all[i].area;
            res[f].estate += all[i].estate;
            res[f].flag = 2;
            counter.insert(f);
        }
    }
    sort(res, res+kMAX, cmp);

    printf("%d\n", counter.size());
    for(int i = 0; i < kMAX; i++){
        if(res[i].flag == 2){
            printf("%04d %d %.3f %.3f\n", res[i].id, res[i].num, res[i].estate / res[i].num, res[i].area/res[i].num);
        }
    }
    
    


    return 0;
}