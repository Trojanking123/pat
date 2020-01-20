#include<iostream>
#include<vector>
#include<queue>

using namespace std;
const int kMAX = 100;

vector<int> Adj[kMAX];
int n;
bool inq[kMAX] = {false};

void BFS(int n){
    queue<int> q;
    q.push(n);
    inq[n] = true;
    while( ! q.empty()){
        int u = q.front();
        q.pop();
        int s = Adj[u].size();
        for(int i = 0; i < s; i++){
            if(inq[Adj[u][i]] == false){
                inq[i] = true;
                q.push(Adj[u][i]);
            }
        }
    }
}

void Traverse(){
    for(int i = 0; i < n; i ++){
        if(inq[i] == false){
            BFS(i);
        }
    }
}

int main(void){



    return 0;
}