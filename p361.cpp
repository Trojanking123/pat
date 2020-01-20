#include<iostream>
#include<queue>

using namespace std;

const int kMAXV = 100;
const int INF = 0x7fffffff;
bool inq[kMAXV] = {false};
int n, G[kMAXV][kMAXV];

void BFS(int u){
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while( !q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(inq[i] == false && G[u][i] != INF ){
                q.push(i);
                inq[i] = true;
            }
        }
    }
}

void Traverse(){
    for(int i = 0; i < n; i++){
        if(inq[i] == false){
            BFS(i);
        }
    }
}
int main(void){





    return 0;
}