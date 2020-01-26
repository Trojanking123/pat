#include<iostream>
#include<algorithm>

using namespace std;

const int kMAX = 505;
const int INF = 0x3f3f3f3f;

int n, m, c1, c2;
int weight[kMAX] = {0};
int w[kMAX] = {0};
int num[kMAX] = {0};
int G[kMAX][kMAX] = {0};
int d[kMAX] = {0};
int vis[kMAX] = {false};

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
        if(u == -1 ) return;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false){
                if(d[u] + G[u][v] < d[v] && G[u][v] != INF){
                    d[v] = d[u] + G[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                }else if(d[v] == d[u] + G[u][v]){
                    num[v] += num[u];
                    if(w[u] + weight[v] > w[v]){
                        w[v] = weight[v] + w[u];
                    }
                }
            }

        }

    }
    return;
}



int main(void){
    cin >> n >> m >> c1 >> c2;
    for(int i = 0; i < n; i++){
        cin >> weight[i];
    }
    fill(G[0], G[0]+kMAX*kMAX, INF);
    for(int i = 0; i < m; i++){
        int s,e, temp;
        cin >> s >> e >> temp;
        G[s][e] = temp;
        G[e][s] = temp;
        
    }
    num[c1] = 1;
    w[c1] = weight[c1];
    dijkstra(c1);
    printf("%d %d\n", num[c2], w[c2]);



    return 0;
}

/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

*/