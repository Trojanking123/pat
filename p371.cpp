#include<iostream>
#include<algorithm>


using namespace std;

const int kMAX = 1005;
const int INF = 0x3fffffff;

int n;
int m;
int s;
int G[kMAX][kMAX];
bool vis[kMAX] = {false};
int d[kMAX];
  
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
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF && d[u]+G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
            }
        }
    }


}


int main(void){

    int u,v,w;
    cin >> n >> m >> s;
    fill(G[0], G[0]+kMAX * kMAX, INF);
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        G[u][v] = w;
    }
    dijkstra(s);
    for(int i = 0; i < n; i++){
        printf("%d ", d[i]);
    }






    return 0;
}