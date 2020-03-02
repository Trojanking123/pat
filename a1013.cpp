#include<iostream>
#include<algorithm>

using namespace std;

const int kMAX = 1005;
const int INF = 0x7f7f7f7f;

int G[kMAX][kMAX] = {0};
bool vis[kMAX]= {false};
int n, m, k;

void DFS(int u){
    vis[u] = true;
    for(int v = 1; v <= n; v++){
        if(G[u][v] && vis[v] == false){
            DFS(v);
        }
    }
}

int getCC(int c){
    int ans = 0;
    fill(vis, vis+kMAX, false);
    vis[c] = true;
    for(int u = 1; u <= n; u++){
        if(vis[u] == false){
            DFS(u);
            ans++;
        }
    }
    return ans;
}

int main(void){
    cin >> n >> m >> k;
    //fill(G[0], G[0]+kMAX*kMAX, INF);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    for(int i = 0; i < k; i++){
        int tmp;
        cin >> tmp;
        printf("%d\n",getCC(tmp)-1);
    }

    return 0;
}