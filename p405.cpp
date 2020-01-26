#include<iostream>
#include<algorithm>

using namespace std;

const int kMAX = 205;
const int INF = 0x7f7f7f7f;

int n,m;

int d[kMAX] = {0};
int G[kMAX][kMAX];
bool vis[kMAX] = {false};

int prim(){
    fill(d, d+kMAX, INF);
    d[0] = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int u = -1;
        int min = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && d[j] < min){
                u = j;
                min = d[j];
            }
        }
        if(u == -1) return -1;
        vis[u] = true;
        ans += d[u];
        for(int v = 0; v < n; v++){
            if(G[u][v] != INF && vis[v] == false && G[u][v] < d[v]){
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}

int main(void){
    fill(G[0], G[0]+kMAX*kMAX, INF);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        G[u][v] = w;
        G[v][u] = w;
    }

    int ans = prim();

    cout<<ans<<endl;






    return 0;
}