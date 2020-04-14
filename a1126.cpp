#include<iostream>
#include<algorithm>

using namespace std;

const int kMAX = 505;
const int INF = 0x3f3f3f3f;

int G[kMAX][kMAX] = {0};
int degree[kMAX] = {0};

int n, e;


int getDegere(int k){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(G[k][i] == 1){
            count++;
        }
    }
    return count;
}

int num = 0;
bool vis[kMAX] = {false};

void DFS(int k){
    vis[k] = true;
    num++;
    for(int i = 1; i <= n; i++){
        if(G[k][i] && (!vis[i])){
            DFS(i);
        }
    }
}



int main(void){
    
    cin >> n >> e;
    
    for( int i = 0; i < e; i++){
        int a,b;
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    DFS(1);

    int temp;

    temp = getDegere(1);
    degree[1] = temp;
    printf("%d", temp);

    for(int i = 2; i <= n; i++){
        temp = getDegere(i);
        degree[i] = temp;
        printf(" %d", temp);
    }
    printf("\n");
    
    

    int odd = 0;
    int even = 0;
    for(int i = 1; i <= n; i++){
        if( degree[i] % 2 == 1){
            odd++;
        }else{
            even++;
        }  
    }
    
    if(num != n ){
        printf("Non-Eulerian\n");
        return 0;
    }
    if( !odd ){
        printf("Eulerian\n");
        return 0;
    }

    if( odd == 2){
        printf("Semi-Eulerian\n");
        return 0;
    }
    printf("Non-Eulerian\n");

    return 0;
}