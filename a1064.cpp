#include<iostream>
#include<algorithm>

using namespace std;
const int kMAX = 1005;
int value[kMAX];
int level[kMAX];
int k = 0;
int n;
void DFS(int x){
    if(x > n) return;
    DFS(x * 2);
    level[x] = value[k++];
    DFS(x*2 + 1);
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> value[i];
    }
    sort(value, value+n);
    DFS(1);
    printf("%d", level[1]);
        
    for(int i = 2; i <= n; i++){
        printf(" %d", level[i]);
    }
    return 0;
}


/*
10
1 2 3 4 5 6 7 8 9 0


6 3 8 1 5 7 9 0 2 4



*/