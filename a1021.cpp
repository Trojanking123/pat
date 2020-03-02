#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

const int kMAX = 10005;
vector<int> Adj[kMAX];
bool vis[kMAX] = {false};
int deepth[kMAX] = {0};
vector<int> dr;
int n;

int BFS(int root){
    deepth[root] = 1;
    vis[root] = true;
    queue<int> q;
    q.push(root);
    int maxD = 1;

    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i = 0; i < Adj[top].size(); i++){
            int id = Adj[top][i];
            if(vis[id] == false){
                q.push(id);
                deepth[id] = deepth[top] + 1;
                vis[id] = true;
                maxD = deepth[id];
            }
        }
    }
    return maxD;
}

int getCC(){
    int ans = 0; 
    for(int i = 0; i < n; i++){
        if(vis[i] == false){
            BFS(i);
            ans++;
        }
    }
    return ans;
}

void getDR(){
    int Max = INT32_MIN;
    for(int i = 0; i < n; i++){
        fill(vis, vis+kMAX, false);
        fill(deepth, deepth+kMAX, 0);
        int m = BFS(i);
        if(m > Max){
            Max = m;
            dr.clear();
            dr.push_back(i);
        }else if(m == Max){
            dr.push_back(i);
        }
    }
}



int main(void){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
    int ans = getCC();
    if(ans > 1){
        printf("Error: %d components\n", ans);
        return 0;
    }

    getDR();
    sort(dr.begin(), dr.end());
    for(int i = 0; i < dr.size(); i++){
        printf("%d\n", dr[i]+1);
    }

    return 0;
}