#include<iostream>
#include<algorithm>


using namespace std;


const int kMAX = 1005;
const int INF = 0x3fffffff;
struct Node{
    int v;
    int dis;
};

vector<Node> Adj[kMAX];
int d[kMAX];
bool vis[kMAX] = {false};
int n;

void dijkstra(int s){
    fill(d, d+kMAX, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1;
        int min = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && d[j] < min){
                u = j;
                min = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;

        for(int j = 0; j < Adj[u].size(); j++){
            int v = Adj[u][j].v;
            if(vis[v] == false && d[u] + Adj[u][j].dis < d[j]){
                d[v] = d[u] + Adj[u][j].dis;
            }
        }

    }
}


int main(void){



    return 0;
}