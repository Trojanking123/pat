#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int kMAX = 505;
const int INF = 0x7f7f7f7f;

int C, n, P, m;


int G[kMAX][kMAX];
bool vis[kMAX] = {false};
int d[kMAX] = {0};
int v[kMAX];


vector<int> path, tmpPath;
int gCarry = INF;
int gBack;

vector<int> pre[kMAX];


void dijkstra(int root){
    fill(d, d+kMAX, INF);
    d[root] = 0;

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
            if(vis[v] == false && G[u][v] != INF){
                if(d[v] > d[u]+ G[u][v]){
                    pre[v].clear();
                    pre[v].push_back(u);
                    d[v] = d[u] + G[u][v];
                }else if(d[v] == d[u]+G[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}



void cal(vector<int> vec, int& carry, int& back){
    reverse(vec.begin(), vec.end());
    carry = 0;
    back = 0;
    int s = vec.size();
    int valve = C/2;
    int w = 0;
    for(int i = 1; i < s; i++){
        if(v[vec[i]] >= valve){
            w += (v[vec[i]]-valve);
        }else{
            int e = valve-v[vec[i]];
            if(e > w){
                carry += e-w;
                w = 0;
            }else{
                w -= e;
            }
        }
    }
    back = w;
    return ;
}

void print(vector<int>& a){
    cout<<"vec:";
    for(int i = 0; i < a.size(); i++){
        printf("%d ", a[i]);
    }
    cout<<endl;
}

void DFS(int root){
    tmpPath.push_back(root);
    if(root == 0){
        //print(tmpPath);
        int carry, back;
        cal(tmpPath, carry, back);
        if(carry < gCarry){
            path = tmpPath;
            gCarry = carry;
            gBack = back;
        }else if(carry == gCarry && back < gBack){
            gBack = back;
            path = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    for(int i = 0; i < pre[root].size(); i++){
        DFS(pre[root][i]);
    }
    tmpPath.pop_back();
}



int main(void){
    
    cin >> C >> n >> P >> m;
    n++;
    for(int i = 1; i < n; i++){
        cin >> v[i];
    }
    fill(G[0], G[0]+kMAX*kMAX, INF);
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        G[a][b] = c;
        G[b][a] = c; 
    }

    pre[0].push_back(0);

    dijkstra(0);

    //cout<<"dij 0k \n";
    DFS(P);
    
    printf("%d ", gCarry);
    reverse(path.begin(), path.end());
    printf("0");
    for(int i = 1; i < path.size(); i++){
        printf("->%d", path[i]);
    }
    printf(" %d\n", gBack);
  

    return 0;
}

/*
10 3 3 5
3 4 10
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1


*/