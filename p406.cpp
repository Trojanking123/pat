#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Edge{
    int next;
    int weight;
    Edge(){};
    Edge(int a, int b):next(a),weight(b){};
};

const int kMAX = 205;
const int INF = 0x7f7f7f7f;

vector<Edge> Adj[kMAX];
int n,m;
int d[kMAX] = {0};
int vis[kMAX] = {false};

int prim(){
    fill(d, d+kMAX, INF);
    d[0] = 0;
    int ans = 0;

    for(int i = 0; i < n; i++){
        int u = -1;
        int min = INF;
        for(int j = 0; j < n; j++){
            if(d[j] < min && vis[j] == false){
                u = j;
                min = d[j];
            }
        }
        if(u == -1) return  -1;
        ans += d[u];
        vis[u] = true;

        for(int k = 0; k < Adj[u].size(); k++){
            int v = Adj[u][k].next;
            int w = Adj[u][k].weight;
            if(vis[v] == false && w < d[v]){
                d[v] = w;
            }
        }

    }

    return ans;




}


int main(void){







    return 0;
}