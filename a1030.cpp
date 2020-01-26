#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int kMAX = 505;
const int INF = 0x3f3f3f3f;

int n, m, S, D;

bool vis[kMAX] = {false};
int d[kMAX] = {0};
int G[kMAX][kMAX] = {0};
int C[kMAX][kMAX] = {0};

vector<int> pre[kMAX];
vector<int> path, tmpPath;
int v = INF;

void print(vector<int>& a){
    cout<< "path: ";
    for(int i = a.size()-1; i >= 0; i--){
        printf("%d ", a[i]);
    }
    cout<<endl;
}

void dijkstra(int start){
    fill(d, d+kMAX, INF);
    d[start] = 0;


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
        //printf("add: %d\n", u);
        vis[u] = true;

        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u); 
                }else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int cal(vector<int>& p){
    int ret = 0;
    for(int i = p.size()-1; i > 0; i--){
        ret += C[p[i]][p[i-1]];
    }
    return ret;
}

int callen(vector<int>& p){
    int ret = 0;
    for(int i = p.size()-1; i > 0; i--){
        ret += G[p[i]][p[i-1]];
    }
    return ret;
}

void BFS(int end){
    if(end == S){
        tmpPath.push_back(end);
        int temp = cal(tmpPath);
        //print(tmpPath);
        if(temp < v){
            
            v = temp;
            path = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    tmpPath.push_back(end);
    for(int i = pre[end].size()-1; i >= 0; i--){
        BFS(pre[end][i]);
    }
    tmpPath.pop_back();

}


int main(void){
    cin >> n >> m >> S >> D;
    fill(G[0], G[0]+kMAX*kMAX, INF);
    fill(C[0], C[0]+kMAX*kMAX, INF);

    for(int i = 0; i < m ; i++){
        int u,v,l,c;
        cin >> u >> v >> l >> c;
        G[u][v] = l;
        G[v][u] = l;
        C[u][v] = c;
        C[v][u] = c;
    }
    //cout<<"input ok\n";

    dijkstra(S);
    //cout<<"dis ok\n";
    BFS(D);
    //cout<<"bfs 0k\n";
    for(int i = path.size()-1; i >= 0; i--){
        printf("%d ", path[i]);
    }
    printf("%d %d\n", callen(path), v);
    return 0;
}